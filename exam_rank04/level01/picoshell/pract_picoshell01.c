#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	count_args(char **av)
{
	int	i = 0;

	while (av[i] != '\0')
		i++;
	return (i);
}

//	count the cmds in matrix
//	create a child for each command - 1
int	picoshell(char **cmds)
{
	int	pid;
	int	fd[2];
	int	prev_fd = -1;
	int	status;
	int	exit_code = 0;
	int	i = 0;

	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(fd) == -1)
			return 1;
		pid = fork();
		if (pid < 0)
		{
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			return (1);
		}
		if (pid == 0)
		{
			//	si hay un comando prev, el comando debe leer del pipe anterior
			//	redirigir stdin al read end del pipe anterior
			if (prev_fd != -1)
			{
				if (dup2(prev_fd, STDIN_FILENO) == -1)
					exit(1);
				close(prev_fd);
			}

			if (cmds[i + 1])
			{
				close(fd[0]);
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}

	}




	return (0);
}
