#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type !- 'w'))
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
	if (pid == 0)	//child process
	{
		if (type == 'r')
		{
			if (dup2(fd[1], STDOUT_FILENO) < 0)
				exit(1);
		}
		if (type == 'w')
		{
			if (dup2(fd[0], STDIN_FILENO) < 0)
				exit(1);
		}
		close(fd[0]);
		close(fd[1]);
		if (execvp(file, argv) == -1)
			exit(1);
	}
	// father process
	if (type == 'r')
	{
		close(fd[1]);	//close escritura, me quedo con lectura
		return (fd[0]);
	}
	if (type == 'w')
	{
		close(fd[0]);	//	cierro lectura, me quedo con escritura
		return (fd[1]);
	}
}

