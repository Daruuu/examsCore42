#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	pid_t	pid;

	pid = fork();
	printf("pid: [%d]\n", pid);
	if (pid == 0)
		printf("hola desde child process\n");
	else
		printf("hola desde proceso PADRE\n");
	return (0);
}

