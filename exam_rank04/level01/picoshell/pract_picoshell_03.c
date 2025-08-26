#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int	picoshell(char **cmds[])
{
	int	count_cmds;
	int	fd[2];
	int	pid;
	int	prev_pipe;
	int	i;

	count_cmds = 0;
	while (cmds[count_cmds] != NULL)
		count_cmds++;

	prev_pipe = -1;
	i = 0;
	while (i < count_cmds)
	{
		if (i < count_cmds - 1)
		{
			if (pipe(fd) == -1)
				return (1);
		}
		pid = fork();
		if (pid < 0)
			return (1);
		if (pid == 0)
		{
			// Si este no es el primer comando, conectamos su entrada estándar (stdin)
			// al extremo de lectura de la tubería anterior.
			if (prev_pipe != -1)
			{
				dup2(prev_pipe, STDIN_FILENO);  // ahora el comando leerá de prev_pipe en vez de stdin
				close(prev_pipe);               // ya no necesitamos este descriptor en el hijo
			}
			// Si este no es el último comando, conectamos su salida estándar (stdout)
			// al extremo de escritura de la nueva tubería.
			if (i < count_cmds - 1)
			{
				dup2(fd[1], STDOUT_FILENO);  // ahora el comando escribirá en la tubería en vez de stdout
				close(fd[0]);                 // cerramos el extremo de lectura de la tubería (no se usa aquí)
				close(fd[1]);                 // cerramos el extremo de escritura original, ya está duplicado
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (prev_pipe != -1)
			close(prev_pipe);
		if (i < count_cmds - 1)
		{
			close(fd[1]);
			prev_pipe = fd[0];
		}
		//while(cmds[i])
		//	i++;
		i++;
	}
	while (wait(NULL) > 0)
		;
	return(0);
}


int main(void)
{
    // Definimos comandos: ls -l | grep .c | wc -l
    char *cmd1[] = {"ls", "-l", NULL};
    char *cmd2[] = {"grep", ".c", NULL};
    char *cmd3[] = {"wc", NULL};
    char **cmds[] = {cmd1, cmd2, cmd3, NULL};

    if (picoshell(cmds) != 0)
    {
        perror("picoshell failed");
        return (1);
    }
    return (0);
}

