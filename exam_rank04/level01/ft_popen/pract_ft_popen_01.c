#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_popen(const char *file, char  *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);

	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
		return -1;

	pid = fork();

	if (pid < 0)
	{
		printf("error creando fork()\n");
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	if (pid == 0)	//	proceso hijo
	{
		if (type == 'r')
		{
			dup2(fd[1], STDOUT_FILENO);
		}
		if (type == 'w')
		{
			dup2(fd[0], STDIN_FILENO);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit(1);
	}
	if (type == 'r')
	{
		close(fd[1]);
		return (fd[0]);
	}
	if (type == 'w')
	{
		close(fd[0]);
		return (fd[1]);
	}
}

// int main(int ac, char **av)
int main()
{

	int fd = ft_popen("ls", (char *const[]) {"ls", "-l", NULL}, 'r');

	if (fd == -1)
	{
		write( 2, "Error in ft_popen\n", 18);
		return (1);
	}

	char    buffer[1024];
	ssize_t bytes;

	while ( (bytes = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes] = '\0';
		write (1, buffer, bytes);
	}
	close(fd);
	return (0);
}
