/*
 * Adaptacion guiada de exam_rank06/subject/main.c para practice01.
 *
 * Regla para decidir que reutilizar:
 *   - Reutilizar la logica que procesa mensajes parciales: las funciones
 *     extract_message() y str_join() ya sirven para TCP.
 *   - Reemplazar la logica de main(): el subject acepta un solo cliente y
 *     termina; practice01 necesita select(), varios clientes y broadcast.
 */

#include <arpa/inet.h>      /* inet_addr() */
#include <netinet/in.h>     /* sockaddr_in */
#include <stdio.h>          /* sprintf() */
#include <stdlib.h>         /* atoi(), calloc(), exit(), malloc() */
#include <string.h>         /* strlen(), strcpy(), strcat(), memset() */
#include <sys/select.h>     /* select(), fd_set */
#include <sys/socket.h>     /* socket(), bind(), listen(), accept(), recv() */
#include <unistd.h>         /* write(), close() */

/*
 * REUTILIZADO DEL SUBJECT SIN CAMBIOS FUNCIONALES:
 * TCP puede entregar una linea en varios recv(), por eso se conserva el
 * buffer parcial y se extrae una linea cada vez que aparece '\n'.
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

/* REUTILIZADO DEL SUBJECT: concatena los datos recibidos al buffer parcial. */
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

/* NUEVO PARA PRACTICE01: error comun exigido por el ejercicio. */
void fatal(void)
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

/* NUEVO PARA PRACTICE01: envia un aviso a todos excepto al emisor. */
void send_all(int except, char* msg, int maxfd, int* ids)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (ids[fd] != -1 && fd != except)
			send(fd, msg, strlen(msg), 0);
	}
}

int main(int argc, char** argv)
{
	/*
	 * NO REUTILIZAR DEL SUBJECT:
	 *
	 * int sockfd, connfd, len;
	 * struct sockaddr_in servaddr, cli;
	 *
	 * El subject solo necesita un descriptor de escucha y uno de cliente.
	 * Aqui hacen falta un conjunto de descriptores, buffers por cliente e IDs.
	 */
	int sock, fd, n;
	int maxfd = 0;
	int next_id = 0;
	int ids[65536];
	char* bufs[65536] = {0};
	fd_set all;
	fd_set readfds;
	struct sockaddr_in addr;
	char buf[1001];
	char msg[100000];

	/* REUTILIZADO DEL SUBJECT, PERO CON ARGUMENTO DE PUERTO. */
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}

	/* REUTILIZADO DEL SUBJECT: crear el socket TCP IPv4. */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		fatal();

	/*
	 * REUTILIZADO DEL SUBJECT:
	 *   bzero(&servaddr, sizeof(servaddr));
	 *   servaddr.sin_family = AF_INET;
	 *   servaddr.sin_addr.s_addr = htonl(2130706433);
	 *   servaddr.sin_port = htons(8081);
	 *
	 * Se usa memset(), inet_addr() y argv[1] para que el puerto sea variable.
	 */
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(atoi(argv[1]));

	/* REUTILIZADO DEL SUBJECT: bind() y listen(). */
	if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0)
		fatal();
	if (listen(sock, 128) < 0)
		fatal();

	/* NUEVO: cada descriptor comienza como libre. */
	for (int i = 0; i < 65536; i++)
		ids[i] = -1;

	/* NUEVO: select() vigila el socket servidor y todos los clientes. */
	FD_ZERO(&all);
	FD_SET(sock, &all);
	maxfd = sock;

	while (1)
	{
		readfds = all;
		if (select(maxfd + 1, &readfds, 0, 0, 0) < 0)
			continue;

		/* El limite evita recorrer descriptores añadidos durante este ciclo. */
		int cur_maxfd = maxfd;
		for (fd = 0; fd <= cur_maxfd; fd++)
		{
			if (!FD_ISSET(fd, &readfds))
				continue;

			if (fd == sock)
			{
				/*
				 * REEMPLAZA AL accept() UNICO DEL SUBJECT:
				 * se acepta cada cliente listo y se vuelve al bucle select().
				 */
				int client = accept(sock, 0, 0);
				if (client < 0)
					continue;
				if (client > maxfd)
					maxfd = client;
				ids[client] = next_id++;
				bufs[client] = NULL;
				FD_SET(client, &all);
				sprintf(msg, "server: client %d just arrived\n", ids[client]);
				send_all(client, msg, maxfd, ids);
			}
			else
			{
				/* NUEVO: recibir datos de cualquier cliente conectado. */
				n = recv(fd, buf, 1000, 0);
				if (n <= 0)
				{
					sprintf(msg, "server: client %d just left\n", ids[fd]);
					send_all(fd, msg, maxfd, ids);
					free(bufs[fd]);
					bufs[fd] = NULL;
					ids[fd] = -1;
					FD_CLR(fd, &all);
					close(fd);
				}
				else
				{
					char* line;

					buf[n] = 0;
					bufs[fd] = str_join(bufs[fd], buf);
					if (!bufs[fd])
						fatal();

					while (extract_message(&bufs[fd], &line) == 1)
					{
						sprintf(msg, "client %d: %s", ids[fd], line);
						send_all(fd, msg, maxfd, ids);
						free(line);
					}
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
