#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int    picoshell(char **cmds[])
{
	int	fd[2];
	int	pid;
	int	prev_pipe;
	int	i;

	prev_pipe = -1;
	i = 0;
	while (cmds[i])
	{
		if (pipe(fd) == -1)
			return (1);
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			if (prev_pipe != -1)
			{
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			if (cmds[i + 1])
			{
				dup2(fd[1], STDOUT_FILENO);
			}
			close(fd[0]);
			close(fd[1]);
			if (execvp(cmds[i][0], cmds[i]) == -1)
				exit(1);
		}
		close(fd[1]);
		if (prev_pipe != -1)
		{
			close(prev_pipe);
		}
		if (!cmds[i + 1])
		{
			close(fd[0]);	
		}
		else
			prev_pipe = fd[0];
		i++;
	}
	while (i--)
		wait(NULL);
	return (0);
}


