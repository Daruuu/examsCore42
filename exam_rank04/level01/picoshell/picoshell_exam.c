#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Simple pipeline executor
int picoshell(char** cmds[])
{
	int prev_pipe;
	// File descriptor of the previous pipe (for stdin redirection)
	int i; // Index for commands
	int fd[2]; // Pipe file descriptors [0]=read, [1]=write
	pid_t pid; // Process ID for fork()

	prev_pipe = -1; // No previous pipe at the beginning
	i = 0;
	while (cmds[i])
	{
		// Create a new pipe for the current command
		if (pipe(fd) == -1)
			return (1);

		// Create a child process
		pid = fork();
		if (pid == -1)
			return (1);

		if (pid == 0) // ---- CHILD PROCESS ----
		{
			// If there is a previous pipe, redirect its read end to stdin
			if (prev_pipe != -1)
			{
				dup2(prev_pipe, STDIN_FILENO);
				close(prev_pipe);
			}
			// If this is not the last command, redirect stdout to the current pipe
			if (cmds[i + 1])
			{
				dup2(fd[1], STDOUT_FILENO);
			}
			// Close unused pipe ends
			close(fd[0]);
			close(fd[1]);

			// Replace the child process with the command
			execvp(cmds[i][0], cmds[i]);
			// If execvp fails, exit with error
			exit(1);
		}
		// ---- PARENT PROCESS ----
		// Close write end of the current pipe (parent doesn’t write here)
		close(fd[1]);

		// Close previous pipe if it exists (no longer needed)
		if (prev_pipe != -1)
			close(prev_pipe);

		// If this is the last command, close the read end too
		if (!cmds[i + 1])
			close(fd[0]);
		else
			// Otherwise, keep this pipe’s read end as the next stdin
			prev_pipe = fd[0];

		i++;
	}
	// Wait for all child processes to finish
	while (i--)
		wait(NULL);

	return (0);
}

int main(void)
{
	// Define commands: echo "hola" | grep "h" | sed 's/h/H/'
	char* cmd1[] = {"echo", "hola", NULL};
	char* cmd2[] = {"grep", "h", NULL};
	char* cmd3[] = {"sed", "s/h/H/", NULL};

	// List of commands (null-terminated)
	char** cmds[] = {cmd1, cmd2, cmd3, NULL};

	// Run pipeline
	if (picoshell(cmds) != 0)
	{
		printf("picoshell error\n");
		return (1);
	}

	return (0);
}
