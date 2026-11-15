#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

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

int	maxfd, next_id;
int	ids[65536];
char *bufs[65536];
fd_set	all;

void	 fatal()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

void	send_all(int except, char *msg)
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
	int sockfd, n;
	int fd = 0;
	struct sockaddr_in servaddr;
	fd_set all;
	if (ac != 2)
	{
		write(2, "Wrong number of arguments.\n", 26);
		return 1;
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		fatal();
	}
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1]));

	if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) <
		0)
	{
		fatal();
	}
	if (listen(sockfd, 128) < 0)
	{
		fatal();
	}
	//	iteramos por toods los fds
	for (int i = 0; i < 65536; i++)
	{
		ids[i] = -1;
	}

	FD_ZERO(&all);
	FD_SET(sockfd, &all);
	maxfd = sockfd;
}