#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	pipefd[2];
	pid_t	pid;
	char	buffer[1024];

	if (pipe(pipefd) < 0)
	{
		printf("pipe\n");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid < 0)
	{
		printf("forkr\n");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		//	proceso hijo
		close(pipefd[1]);	//	el hijo no escribe, solo lee
		read(pipefd[0], buffer, sizeof(buffer));
		printf("Hijo recibio: %s\n", buffer);
	}
	return (0);
}
