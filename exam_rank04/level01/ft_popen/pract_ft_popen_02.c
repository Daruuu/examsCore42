#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int    ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);
	int	pid;
	int	fd[2];

	if (pipe(fd) < 0)
	{
		return (-1);
	}
	pid = fork();
	if (pid < 0)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	if (pid == 0)	//process hijo
	{
		//	canal 0 = input
		//	canal 1 = output 
		if (type == 'r')
		{
			dup2(fd[1], STDOUT_FILENO);
		}
		if (type == 'w')
		{
			dup2(fd[0], STDIN_FILENO);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit(1);
	}
	if (type == 'r')
	{
		close(fd[1]);
		return (fd[0]);
	}
	if (type == 'w')
	{
		close(fd[0]);
		return (fd[1]);
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*str)
		write(1, str++, 1);
}

int main()
{
    int  fd;
    char buffer[1024];
	ssize_t	bytes;

	fd = ft_popen("ls", (char *const []){"ls", "-l", NULL}, 'r');
	if (fd == -1)
		return (1);

    while ((bytes = read(fd, buffer, sizeof(buffer) - 1)) > 0)
	{
		buffer[bytes] = '\0';
		printf("%s", buffer);
	}
    return (0);
}
