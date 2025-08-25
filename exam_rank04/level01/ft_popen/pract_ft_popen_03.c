#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (1);

	int	pid;
	int	fd[2];
	
	if (pipe(fd) < 0)
	{
		return(1);
	}
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (1);
	}
	if (pid == 0)	//	child process
	{
		if (type == 'r')
		{
			close(fd[0]);
			if (dup2(fd[1], STDOUT_FILENO) < 0)
				exit(1);
		}
		if (type == 'w')
		{
			close(fd[1]);
			if (dup2(fd[0], STDIN_FILENO) < 0)
				exit(1);
		}
		close(fd[0]);
		close(fd[1]);
		if (execvp(file, av) == -1)
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

