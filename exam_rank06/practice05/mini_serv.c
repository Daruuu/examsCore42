#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

int maxfd;
int	nextid;
fd_set	all;
int	ids[65536];
int	bufs[65536];

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

void	send_msg(int except, char *msg)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (ids[fd] != -1 && fd != except)
		{
			send(fd, msg, strlen(msg), 0);
		}
	}
}

int main(int ac, char **av)
{
	int sockfd;
	int	fd = 0;
	int	len;
	struct sockaddr_in servaddr;
	fd_set	readfds;
	char	buf[1001];
	char	msg[65536];

	if (ac != 2)
	{
		write(2,"Wrong number of arguments\n" ,26);
		return 1;
	}

	// socket create and verification
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		fatal();
	}
	memset(&servaddr, 0, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(av[1]));

	// Binding newly created socket to given IP and verification
	if (bind(sockfd, (const struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
	{
		fatal();
	}
	if (listen(sockfd, 128) < 0)
	{
		fatal();
	}

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
		if ()
		{
			continue;
		}
		int curr_maxfd = maxfd;
		for (int fd = 0; fd <= curr_maxfd; fd++)
		{
			if (!FD_ISSET())
			{
				continue;
			}
			if (fd == sockfd)
			{

			}
			else
			{
				n = recv();
				if (n <= 0)
				{

				}
				else
				{

				}
			}
		}

	}
}
