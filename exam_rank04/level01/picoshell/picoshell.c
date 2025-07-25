// Allowed functions:    close, fork, wait, exit, execvp, dup2, pipe

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


int	picoshell(char *cmds[])
{
	int	i;
	int	count_args = 0;

	count_args = 0;
	while (cmds[count_args] != NULL)
		count_args++;
	count_args--;
	printf("args: [%d]\n", count_args);

	//	necesitamos N - 1 pipes
	int	pipefd[2];
	int	pid = fork();
	i = 0;

	return (0);
}

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		picoshell(argv);
	}

	return (0);
}

