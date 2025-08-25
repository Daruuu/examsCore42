#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	count_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	picoshell(char *cmds[])
{
	int	n_cmds;
	int	prev_pipe;
	int	fd[2];
	int	pid;
	int	i;

	n_cmds = count_args(cmds);
	i = 0;
	while (i < n_cmds)
	{
		if (pipe(fd) < 0)
		{
			return (1);
		}
		pid = fork();
		if (pid < 0)
			return (1);
		if (pid == 0)	//	process child
		{
			//	si hay una pipe anterior, redirigimos la entrada
			if (prev_pipe != -1)
			{
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			//	si no es el ultimo comando, redirigir la salida al pipe actual
			if (i < n_cmds - 1)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			execvp(cmds[i], &cmds[i]);
			exit (1);
		}
		//	PROCESS  padre: CLOSE FDs innecesarios
		if (prev_pipe != -1)
			close(prev_pipe);
		if (i < n_cmds - 1)
		{
			close(fd[1]);
			prev_pipe = fd[0];
		}
		//	avanzar al next command (skip argumentos del actual)
		while (cmds[i])
			i++;
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}

int	main(void)
{
		//"sed", "s/word/universe/", NULL,
	char	*cmds[] = {
		"ls","-l", NULL,
		"wc", "-l", NULL,
		NULL
	};
	return (picoshell(cmds));
}
