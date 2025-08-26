#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	int	fd[2];
	int	pid;
	if (pipe(fd) < 0)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			if (dup2(fd[1], STDOUT_FILENO) < 0)
				exit (1);
		}
		if (type == 'w')
		{
			if (dup2(fd[0], STDIN_FILENO) < 0)
				exit (1);
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
	return (0);
}

int	main()
{
	int	fd;
	char	buffer[1024];
	ssize_t	bytes;

	fd = ft_popen("ls", (char *const[]){"ls", "-l", NULL}, 'r');
	if (fd == -1)
		return(1);
	while ((bytes = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes] = '\0';
		printf("%s", buffer);
	}
	close(fd);
	return (0);
}
