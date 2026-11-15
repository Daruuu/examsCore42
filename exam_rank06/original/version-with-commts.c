#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <netinet/in.h>

/* ============================================================
   BLOQUE 2 — VARIABLES GLOBALES
   ============================================================ */

// Descriptor más alto que vigilamos con select().
int maxfd;
// ID que asignaremos al siguiente cliente. empieza en 0.
int next_id;
// Relación: descriptor (fd) -> ID lógico del cliente.
// -1 significa que ese descriptor no es un cliente activo.
int ids[65536];
// Buffer individual de cada cliente.
char* bufs[65536];
// Conjunto de sockets que queremos vigilar.
fd_set all;

// Termina el programa cuando ocurre un error fatal.
void fatal(void)
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

/*Envía un mensaje a todos los clientes EXCEPTO a uno.
 * except = fd del cliente que no debe recibir el mensaje.*/
void send_all(int except, char* msg)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		// Solo clientes activos y distintos del emisor.
		if (ids[fd] != -1 && fd != except)
			send(fd, msg, strlen(msg), 0);
	}
}

int main(int argc, char** argv)
{
	int sockfd;
	int fd = 0;
	int n;

	struct sockaddr_in servaddr;

	// Copia del conjunto de sockets usada por select().
	fd_set readfds;

	// recv() leerá como máximo 1000 bytes.
	// Reservamos uno adicional para el terminador '\0'.
	char buf[1001];
	char msg[100000]; // Buffer donde construimos los mensajes a enviar.

	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (1);
	}
	/* socket(): AF_INET -> IPv4
	* SOCK_STREAM -> TCP
	* 0           -> protocolo predeterminado*/
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		fatal();

	// Init la estructura de dirección.
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	// htonl() convierte a orden de bytes de red.
	servaddr.sin_addr.s_addr = htonl(2130706433); // 2130706433 equivale a 127.0.0.1.
	// htons() convierte el puerto a orden de bytes de red.
	servaddr.sin_port = htons(atoi(argv[1]));
	// bind(): Asocia el socket a la IP y al puerto indicados.
	if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		fatal();

	/* listen(): Pone el socket en modo escucha.
	* 128 es el backlog solicitado para conexiones pendientes.*/
	if (listen(sockfd, 128) < 0)
		fatal();
	for (int i = 0; i < 65536; i++)
		ids[i] = -1;

	FD_ZERO(&all);	//vacía el conjunto de sockets.
	FD_SET(sockfd, &all);	// añade el socket servidor al conjunto.
	maxfd = sockfd;

	/* ========================================================
		BLOQUE 6 — BUCLE PRINCIPAL
		======================================================== */
	while (1)
	{
		/*
		* IMPORTANTE:
		* select() modifica el conjunto que recibe.
		* Por eso hacemos una COPIA de 'all'.
		* 'all' contiene todos los sockets vigilados.
		* 'readfds' indicará cuáles están listos para leer.
		*/
		readfds = all;

		/*
		* select():
		* maxfd + 1 -> rango de descriptores comprobados.
		* &readfds  -> sockets que queremos comprobar para lectura.
		* 0         -> no vigilamos escritura.
		* 0         -> no vigilamos excepciones.
		* 0         -> espera indefinidamente.
		* Se desbloquea cuando hay actividad.
		*/
		if (select(maxfd + 1, &readfds, 0, 0, 0) < 0)
			continue;

		int cur_maxfd = maxfd;	// Guardamos el máximo actual antes de recorrer los fd.
		for (fd = 0; fd <= cur_maxfd; fd++)
		{
			/*
			* FD_ISSET: * ¿Está este descriptor preparado para leer?
			* Si no está listo, pasamos al siguiente.*/
			if (!FD_ISSET(fd, &readfds))
				continue;

			/* =================================================
				BLOQUE 7 — NUEVA CONEXIÓN
				================================================= */

			/*
			* Si el descriptor preparado es sockfd,
			* hay una conexión nueva pendiente de aceptar.
			*/
			if (fd == sockfd)
			{
				/*
				* accept():
				* Acepta la nueva conexión y devuelve
				* un NUEVO descriptor para ese cliente.
				*
				* sockfd sigue siendo el socket servidor.
				*/
				int client = accept(sockfd, 0, 0);

				if (client < 0)
					continue;

				// Actualizamos el descriptor máximo.
				if (client > maxfd)
					maxfd = client;

				/*
				* Cada cliente recibe un ID consecutivo.
				*
				* IMPORTANTE:
				* El ID del cliente NO es su file descriptor.
				*/
				ids[client] = next_id++;

				// Inicialmente no hay mensajes pendientes.
				bufs[client] = NULL;

				// Empezamos a vigilar el nuevo cliente.
				FD_SET(client, &all);

				// Avisamos a los demás clientes.
				sprintf(msg,
						"server: client %d just arrived\n",
						ids[client]);

				send_all(client, msg);
			}

			/* =================================================
				BLOQUE 8 — ACTIVIDAD DE UN CLIENTE
				================================================= */

			else
			{
				/*
				* recv():
				* Lee hasta 1000 bytes del cliente.
				*
				* n > 0: hemos recibido datos.
				* n = 0: el cliente cerró la conexión.
				* n < 0: error de recepción.
				*/
				n = recv(fd, buf, 1000, 0);

				/* ---------------------------------------------
					CASO A — CLIENTE DESCONECTADO
					--------------------------------------------- */

				if (n <= 0)
				{
					// Notificamos la salida al resto.
					sprintf(msg,
							"server: client %d just left\n",
							ids[fd]);

					send_all(fd, msg);

					// Liberamos datos pendientes del cliente.
					free(bufs[fd]);
					bufs[fd] = NULL;

					// Marcamos su descriptor como inactivo.
					ids[fd] = -1;

					/*
					* FD_CLR:
					* Dejamos de vigilar este descriptor.
					*/
					FD_CLR(fd, &all);

					// Cerramos el socket del cliente.
					close(fd);
				}

				/* ---------------------------------------------
					CASO B — CLIENTE ENVÍA DATOS
					--------------------------------------------- */

				else
				{
					char* line;

					// Convertimos los bytes recibidos en string.
					buf[n] = 0;

					/*
					* Añadimos los datos recibidos al buffer
					* pendiente de este cliente.
					*
					* Ejemplo:
					* anterior = "ho"
					* recibido = "la\n"
					* resultado = "hola\n"
					*/
					bufs[fd] = str_join(bufs[fd], buf);

					if (!bufs[fd])
						fatal();

					/*
					* IMPORTANTE:
					* Un recv() puede contener varias líneas.
					*
					* Por eso utilizamos WHILE, no IF.
					*
					* Procesamos todas las líneas completas
					* disponibles, una por una.
					*/
					while (extract_message(&bufs[fd],
											&line) == 1)
					{
						/*
						* Añadimos el ID del emisor antes
						* de cada línea.
						*/
						sprintf(msg, "client %d: %s",
								ids[fd], line);

						// Enviamos la línea a todos menos al emisor.
						send_all(fd, msg);

						// Liberamos la línea ya procesada.
						free(line);
					}

					/*
					* Si el buffer pendiente quedó vacío,
					* liberamos su memoria.
					*
					* Si contiene una línea incompleta,
					* la conservamos para el próximo recv().
					*/
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
