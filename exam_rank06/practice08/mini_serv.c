#include <inttypes.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

int	maxfd;
int	next_id;
int	ids[65536];
char *bufs[65536];
fd_set	all;

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

void	fatal()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

void	send_all(int except, char *msg)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (ids[fd] != -1 && fd != except)
			send(fd, msg, strlen(msg), 0);
	}
}

int main(int ac, char **av)
{
	int sockfd;
	int fd;
	int n;
	char buf[1001];
	char msg[65536];
	struct sockaddr_in servaddr;
	fd_set	readfds;

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		fatal();
	memset(&servaddr, 0, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	// Binding newly created socket to given IP and verification
	if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		fatal();
	if (listen(sockfd, 128) < 0)
		fatal();
	for (int i = 0; i < maxfd; i++)
	{
		ids[i] = -1;
	}
	FD_ZERO(&all);
	FD_SET(sockfd, &all);
	maxfd = sockfd;

	while (1)
	{
		readfds = all;
		if (select(maxfd + 1, &readfds ,0, 0, 0) < 0)
			continue;

		int	curr_maxfd = maxfd;
		for (fd = 0; fd < curr_maxfd; fd++)
		{
			if (!FD_ISSET(fd, &readfds))
				continue;
			if (fd == sockfd)
			{
				int	client = accept(sockfd, 0, 0);
				if (client < 0)
					continue;
				if (client > maxfd)
					maxfd = client;
				ids[client] = next_id++;
				bufs[client] = NULL;
				FD_SET(client, &all);

				sprintf(msg, "server: client %d just arrived\n", ids[client]);
				send_all(client,msg);
			}
			else
			{
				n = recv(fd, buf, 1000, 0);
				if (n <= 0)
				{
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
					char *line;

					buf[n] = 0;
					bufs[fd] = str_join(bufs[fd], buf);
					if (!bufs[fd])
						fatal();

					while (extract_message(&bufs[fd], &line) == 1)
					{
						sprintf(msg, "client %d %s", ids[fd], line);
						send_all(fd, msg);
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

	/*
	len = sizeof(cli);
	connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
	if (connfd < 0)
	{
		printf("server acccept failed...\n");
		exit(0);
	}
	else
		printf("server acccept the client...\n");
	*/
}
