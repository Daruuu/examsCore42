#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

/*
 * Estado global del servidor.
 * ids[fd]  relaciona cada descriptor con el ID del cliente.
 * bufs[fd] almacena datos que aún no forman una línea terminada en '\n'.
 * all      contiene todos los descriptores vigilados por select().
 */
int maxfd, next_id;
int ids[65536];
char* bufs[65536];
fd_set all;

/* Escribe el error exigido, termina el proceso y devuelve estado 1. */
void fatal(void)
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

/* Envía msg a todos los clientes conectados excepto except. */
void send_all(int except, char* msg)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (ids[fd] != -1 && fd != except)
			send(fd, msg, strlen(msg), 0);
	}
}

/*
 * Extrae la primera línea completa de buf.
 *
 * Si buf contiene "hola\nadios\n", msg recibe "hola\n" y buf conserva
 * "adios\n". Retorna 1 si extrae una línea, 0 si todavía está incompleta
 * y -1 si falla una reserva de memoria.
 */
int extract_message(char** buf, char** msg)
{
	char* newbuf;
	int i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

/*
 * Concatena add al buffer buf. Es necesario porque TCP puede entregar una
 * línea en varios recv(). Crea un buffer nuevo y libera el anterior.
 */
char* str_join(char* buf, char* add)
{
	char* newbuf;
	int len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

/*
 * Punto de entrada del servidor.
 * Crea el socket, acepta clientes y usa select() para procesar conexiones
 * y datos sin bloquearse esperando a un cliente concreto.
 */
int main(int argc, char** argv)
{
	int sock, fd, n; // socket servidor, fd actual y número de bytes recibidos
	struct sockaddr_in addr; // dirección IP y puerto del servidor
	fd_set readfds; // copia de all modificada por select()
	char buf[1001]; // bloque temporal de recepción
	char msg[100000]; // mensaje que será enviado a otros clientes

	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}

	/* Crea un socket TCP IPv4. */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		fatal();

	/* Configura el servidor para escuchar únicamente en 127.0.0.1. */
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(atoi(argv[1]));

	/* Asocia el socket al puerto y lo pone en modo escucha. */
	if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0)
		fatal();
	if (listen(sock, 128) < 0)
		fatal();

	/* Inicialmente todos los descriptores están marcados como libres. */
	for (int i = 0; i < 65536; i++)
		ids[i] = -1;

	/* El socket servidor también debe ser vigilado por select(). */
	FD_ZERO(&all);
	FD_SET(sock, &all);
	maxfd = sock;

	while (1)
	{
		/* select() modifica el conjunto recibido, por eso se usa una copia. */
		readfds = all;
		if (select(maxfd + 1, &readfds, 0, 0, 0) < 0)
			continue;

		int cur_maxfd = maxfd;
		for (fd = 0; fd <= cur_maxfd; fd++)
		{
			if (!FD_ISSET(fd, &readfds))
				continue;

			if (fd == sock)
			{
				/* El socket servidor está listo: hay un cliente esperando. */
				int client = accept(sock, 0, 0);
				if (client < 0)
					continue;

				if (client > maxfd)
					maxfd = client;

				ids[client] = next_id++;
				bufs[client] = NULL;
				FD_SET(client, &all);

				sprintf(msg, "server: client %d just arrived\n", ids[client]);
				send_all(client, msg);
			}
			else
			{
				/* Un cliente existente tiene datos disponibles para leer. */
				n = recv(fd, buf, 1000, 0);

				if (n <= 0)
				{
					/* recv()==0 significa desconexión; un valor negativo es un error. */
					sprintf(msg, "server: client %d just left\n", ids[fd]);
					send_all(fd, msg);

					free(bufs[fd]);
					bufs[fd] = NULL;
					ids[fd] = -1;

					FD_CLR(fd, &all);
					close(fd);
				}
				else
				{
					char* line;

					/* Añade un terminador para tratar el bloque como cadena C. */
					buf[n] = 0;
					bufs[fd] = str_join(bufs[fd], buf);
					if (!bufs[fd])
						fatal();

					/* Un recv() puede contener una o varias líneas completas. */
					while (extract_message(&bufs[fd], &line) == 1)
					{
						sprintf(msg, "client %d: %s", ids[fd], line);
						send_all(fd, msg);
						free(line);
					}

					/* Libera el buffer cuando solo queda una cadena vacía. */
					if (bufs[fd] && bufs[fd][0] == '\0')
					{
						free(bufs[fd]);
						bufs[fd] = NULL;
					}
				}
			}
		}
	}
}
