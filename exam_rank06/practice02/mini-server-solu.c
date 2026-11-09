/* ************************************************************************** */
/*                                                                            */
/*   mini_serv_memorizar.c                                                    */
/*                                                                            */
/*   El mismo código que lil_mini_serv_fixed.c, separado en 11 PASOS.         */
/*                                                                            */
/*   MAPA (apréndetelo primero):                                              */
/*     PASO 0  Copiar del main dado ..... "Lo que me dan, lo copio"           */
/*     PASO 1  Globales ................. "Máximo, siguiente, ids,            */
/*                                         buffers, todos"                    */
/*     PASO 2  fatal + send_all ......... "Morir y gritar a todos"            */
/*     PASO 3  Variables de main ........ "sock, fd, n, addr, readfds,        */
/*                                         buf, msg"                          */
/*     PASO 4  Argumentos ............... "¿Me has dado el puerto?"           */
/*     PASO 5  Crear el servidor ........ "S-A-B-L: Socket, Addr, Bind,       */
/*                                         Listen"                            */
/*     PASO 6  Preparar select .......... "Nadie, vacío, servidor, máximo"    */
/*     PASO 7  Bucle + select ........... "Copio y duermo"                    */
/*     PASO 8  Recorrer los fd .......... "¿Quién ha levantado la mano?"      */
/*     PASO 9  Cliente nuevo ............ "Acepto, numero, apunto, aviso"     */
/*     PASO 10 Cliente se va ............ "Aviso, libero, borro, cierro"      */
/*     PASO 11 Cliente escribe .......... "Cierro cadena, junto, saco         */
/*                                         líneas, envío, limpio"             */
/*                                                                            */
/*   Compilar y probar:                                                       */
/*     gcc -Wall -Wextra -Werror mini_serv_memorizar.c -o mini_serv           */
/*     ./mini_serv 8081                                                       */
/*     nc 127.0.0.1 8081        (en 2 o 3 terminales más)                     */
/*                                                                            */
/* ************************************************************************** */


/* ========================================================================== */
/*  PASO 0 · COPIAR DEL MAIN DADO                 "Lo que me dan, lo copio"   */
/*  - Includes: el main dado trae algunos; AÑADE stdlib, stdio y sys/select.  */
/*  - extract_message y str_join: se copian TAL CUAL, no hay que memorizar.   */
/* ========================================================================== */

#include <unistd.h>       // write, close
#include <stdlib.h>       // malloc, calloc, free, exit, atoi
#include <string.h>       // strlen, strcpy, strcat, memset
#include <stdio.h>        // sprintf
#include <sys/socket.h>   // socket, bind, listen, accept, send, recv
#include <sys/select.h>   // select, FD_ZERO, FD_SET, FD_CLR, FD_ISSET
#include <netinet/in.h>   // struct sockaddr_in, htons, htonl

/* --- copiada del main dado: saca UNA línea (hasta '\n') de *buf --- */
int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

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

/* --- copiada del main dado: devuelve buf + add y libera el buf viejo --- */
char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

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


/* ========================================================================== */
/*  PASO 1 · GLOBALES          "Máximo, siguiente, ids, buffers, todos"       */
/* ========================================================================== */

int		maxfd, next_id;		// Máximo, siguiente
int		ids[65536];			// ids:      fd -> id del cliente (-1 = nadie)
char	*bufs[65536];		// buffers:  fd -> texto pendiente sin '\n'
fd_set	all;				// todos:    los fd que vigilamos


/* ========================================================================== */
/*  PASO 2 · FATAL + SEND_ALL                     "Morir y gritar a todos"    */
/* ========================================================================== */

void	fatal(void)
{
	write(2, "Fatal error\n", 12);		// 2 = stderr, 12 = letras
	exit(1);
}

void	send_all(int except, char *msg)
{
	for (int fd = 0; fd <= maxfd; fd++)
		if (ids[fd] != -1 && fd != except)	// es cliente Y no es el excluido
			send(fd, msg, strlen(msg), 0);
}


int	main(int argc, char **argv)
{
	/* ====================================================================== */
	/*  PASO 3 · VARIABLES DE MAIN                                            */
	/*           "sock, fd, n, addr, readfds, buf, msg"                       */
	/* ====================================================================== */

	int					sock, fd, n;
	struct sockaddr_in	addr;
	fd_set				readfds;
	char				buf[1001];		// 1000 de recv + 1 para el '\0'
	char				msg[64];		// solo avisos y el prefijo


	/* ====================================================================== */
	/*  PASO 4 · ARGUMENTOS                      "¿Me has dado el puerto?"    */
	/* ====================================================================== */

	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);	// 26 = letras
		return (1);
	}


	/* ====================================================================== */
	/*  PASO 5 · CREAR EL SERVIDOR    "S-A-B-L: Socket, Addr, Bind, Listen"   */
	/*           Cada llamada al sistema: si < 0 → fatal()                    */
	/* ====================================================================== */

	// S · Socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0)
		fatal();

	// A · Addr: familia, IP, puerto
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(2130706433);	// 127.0.0.1 (viene en el main dado)
	addr.sin_port = htons(atoi(argv[1]));

	// B · Bind
	if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
		fatal();

	// L · Listen
	if (listen(sock, 128) < 0)
		fatal();


	/* ====================================================================== */
	/*  PASO 6 · PREPARAR SELECT       "Nadie, vacío, servidor, máximo"       */
	/* ====================================================================== */

	for (int i = 0; i < 65536; i++)		// Nadie
		ids[i] = -1;
	FD_ZERO(&all);						// vacío
	FD_SET(sock, &all);					// servidor
	maxfd = sock;						// máximo


	while (1)
	{
		/* ================================================================== */
		/*  PASO 7 · BUCLE + SELECT                       "Copio y duermo"    */
		/*           +1, &readfds, tres ceros                                 */
		/* ================================================================== */

		readfds = all;										// Copio
		if (select(maxfd + 1, &readfds, 0, 0, 0) < 0)		// y duermo
			continue;


		/* ================================================================== */
		/*  PASO 8 · RECORRER LOS FD       "¿Quién ha levantado la mano?"     */
		/*                                                                    */
		/*      ¿fd == sock?                                                  */
		/*       ├─ sí → PASO 9  (cliente nuevo)                              */
		/*       └─ no → recv                                                 */
		/*                ├─ n <= 0 → PASO 10 (se va)                         */
		/*                └─ n > 0  → PASO 11 (escribe)                       */
		/* ================================================================== */

		int cur_maxfd = maxfd;					// congelado: maxfd puede subir
		for (fd = 0; fd <= cur_maxfd; fd++)
		{
			if (!FD_ISSET(fd, &readfds))		// no levantó la mano → siguiente
				continue;

			if (fd == sock)
			{
				/* ========================================================== */
				/*  PASO 9 · CLIENTE NUEVO                                    */
				/*           "Acepto, numero, apunto, aviso"                  */
				/* ========================================================== */

				int client = accept(sock, 0, 0);		// Acepto
				if (client < 0)
					continue;
				if (client > maxfd)
					maxfd = client;
				ids[client] = next_id++;				// numero
				bufs[client] = NULL;
				FD_SET(client, &all);					// apunto
				sprintf(msg, "server: client %d just arrived\n", ids[client]);
				send_all(client, msg);					// aviso (menos a él)
			}
			else
			{
				n = recv(fd, buf, 1000, 0);

				if (n <= 0)
				{
					/* ====================================================== */
					/*  PASO 10 · CLIENTE SE VA                               */
					/*            "Aviso, libero, borro, cierro"              */
					/*  (primero avisar: ids[fd] todavía tiene el número)     */
					/* ====================================================== */

					sprintf(msg, "server: client %d just left\n", ids[fd]);
					send_all(fd, msg);					// Aviso
					free(bufs[fd]);						// libero
					bufs[fd] = NULL;
					ids[fd] = -1;						// borro
					FD_CLR(fd, &all);
					close(fd);							// cierro
				}
				else
				{
					/* ====================================================== */
					/*  PASO 11 · CLIENTE ESCRIBE                             */
					/*   "Cierro cadena, junto, saco líneas, envío, limpio"   */
					/* ====================================================== */

					char	*line;

					buf[n] = 0;										// Cierro cadena
					bufs[fd] = str_join(bufs[fd], buf);				// junto
					if (!bufs[fd])
						fatal();

					while (extract_message(&bufs[fd], &line) == 1)	// saco líneas
					{
						sprintf(msg, "client %d: ", ids[fd]);		// envío:
						for (int i = 0; i <= maxfd; i++)			// prefijo + línea
						{											// a todos menos fd
							if (ids[i] != -1 && i != fd)
							{
								send(i, msg, strlen(msg), 0);
								send(i, line, strlen(line), 0);
							}
						}
						free(line);
					}

					if (bufs[fd] && bufs[fd][0] == '\0')			// limpio
					{
						free(bufs[fd]);
						bufs[fd] = NULL;
					}
				}
			}
		}
	}
}