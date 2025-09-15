#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	int	fd[2];
	int	pid;
	
	if (pipe(fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	if (pid == 0)
	{
		if (type == 'r')
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				exit(1);
		}
		if (type == 'w')
		{
			if (dup2(fd[0], STDIN_FILENO) == -1)
				exit(1);
		}
		close(fd[0]);
		close(fd[1]);
		if (execvp(file, argv) == -1)
			exit(1);
	}
	return (0);
}

int	main()
{
	int		fd;
	char	*args[] = {"echo", "hello world", NULL};

	fd = ft_popen(args[0], args, 'r');
	if (fd < 0)
	{
		perror("ft popen");
		return (1);
	}

	char	buf[128];
	ssize_t	n = read(fd, buf, sizeof(buf) -1);
	if (n > 0)
	{
		buf[n] = '\0';
		printf("output: %s", buf);
	}
	close(fd);
	return (0);
}

