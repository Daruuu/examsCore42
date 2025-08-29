#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//	count cmds
//	while e iterar por todos hasta -1

int    picoshell(char **cmds[])
{
	int	n_cmds;
	int	pid;
	int	fd[2];
	int	prev_pipe;
	int	i;

	n_cmds = 0;
	while (cmds[n_cmds])
		n_cmds++;

	i = 0;
	prev_pipe = -1;

	while (i < n_cmds)
	{
		if (i < n_cmds - 1)
		{
			if (pipe(fd) == -1)
				return (1);
		}
		pid = fork();
		if (pid < 0)
			return (1);
		if (pid == 0)//	child process
		{
			// existe pipe anterior
			if (prev_pipe != -1)
			{
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			if (i < n_cmds - 1)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (prev_pipe != -1)
			close(prev_pipe);
		if (i < n_cmds - 1)
		{
			close(fd[1]);
			prev_pipe = fd[0];
		}
		i++;
	}
	while (wait(NULL) > 0)
		;
	return(0);
}

int	main()
{
	char	*cmd1[] = {"ls","-l", NULL};
	char	*cmd2[] = {"grep", ".c", NULL};
	char	*cmd3[] = {"wc", NULL};

	char	**cmdss[] = {cmd1, cmd2, cmd3, NULL};
	
	if(picoshell(cmdss) != 0)
	{
		write(2, "picoshell failed\n", 17);
		return (1);
	}
	return (0);
}
