// Allowed functions:    close, fork, wait, exit, execvp, dup2, pipe

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

int	count_cmds(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i] != NULL)
		i++;
	return (i);
}

// Esta función ejecuta múltiples comandos conectados con pipes como un shell:
// cmds = {"echo", "hi", NULL, "cat", NULL, "sed", "s/i/I/", NULL, NULL}

int	picoshell(char *cmds[])
{
	int	num_cmds;
	int	prev_pipe;	//file descriptor de lectura del pipe anterior
	int	pipefd[2];	// pipe actual [0]: read, [1]: write
	int	pid;
	int	i;

	num_cmds = count_cmds(cmds);
	prev_pipe = -1;
	pid = 0;

	i = 0;
	while (i < num_cmds)
	{
		if (i < num_cmds - 1)
		{
			if (pipe(pipefd) == -1)
				return (1);
		}
		pid = fork();
		if (pid < 0)
			return (1);
		if (pid == 0)	//es el proceso hijo
		{
			//	si hay una pipe anterior, redirigir entrada desde el
			if (prev_pipe != -1)
			{
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			// Si no es el último comando, redirigir salida al pipe actual
			if (i < num_cmds - 1)
			{
				dup2(pipefd[1], STDOUT_FILENO);
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i], &cmds[i]);
			exit(1);
		}
		//	proceso padre: CLOSE  FDS innecesarios
		if (prev_pipe != -1)
			close(prev_pipe);
		if (i < num_cmds - 1)
		{

			close(pipefd[1]);
			prev_pipe = pipefd[0];
		}
		// Avanzar al siguiente comando (saltando argumentos del actual)
		while (cmds[i])
			i++;
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}

// int main(int argc, char* argv[])
int main(void)
{
	char *cmds[] = {
		"echo", "hello world", NULL,
		"cat", NULL,
		"sed", "s/world/universe/", NULL,
		NULL
	};
	return (picoshell(cmds));
}

