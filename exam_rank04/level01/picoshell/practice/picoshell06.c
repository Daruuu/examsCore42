#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int	fd[2];
	int	prev_pipe;
	int	pid;
	int	i;

	prev_pipe = -1;
	i = 0;
	while (cmds[i])
	{
		if (pipe(fd) == -1)
		{
			return (1);
		}
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			if (prev_pipe != -1)
			{
				dup2(prev_pipe, STDIN_FILENO);
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
			close(prev_pipe);
		if (!cmds[i + 1])
			close(fd[0]);
		else
			prev_pipe = fd[0];
		i++;
	}
	while (i--)
		wait(NULL);
	return (0);
}

int	main()
{
	char	*cmd1[] = {"ls", "-l", NULL};
	char	*cmd2[] = {"grep", "ll", NULL};
	char	*cmd3[] = {"sed", "s/ll/ABA/", NULL};

	char	**cmds[] = {cmd1, cmd2, cmd3, NULL};

	if (picoshell(cmds) != 0)
	{
		printf("picoshell err\n");
		return (1);
	}
	return (0);
}

