#include <unistd.h>
#include <stdlib.h>

void    ft_putstr(char *str)
{
    int i;

    if (str == NULL)
    {
        return ;
    }
    
    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_popen(const char file, char const argv[], char type)
 {
    if (!file || !argv || (type != 'r' && type != 'w'))
    {
        return (-1);
    }

    int fd[2];
    int pid;

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
    if (pid == 0)
    {
        if (type == 'r')
        {
            close(fd[0]);
            if (dup2(fd[1], STDOUT_FILENO) < 0)
            {
                exit (-1);
            }
        }
        else    // if (type == 'w')
        {
            close(fd[1]);
            if (dup2(fd[0], STDIN_FILENO) < 0)
            {
                exit (-1);
            }
        }
        close(fd[0]);
        close(fd[1]);
        if (execvp(file, argv) == -1)
            exit(-1);
    }
    if (type == 'r')
    {
        close(fd[0]);
        return (fd[0]);
    }
    else
    {
        close(fd[0]);
        return (fd[1]);
    }
 }

 int    main(int ac, char **av)
 {
    int fd =  ft_popen("ls", (char const[]){"ls", NULL}, 'r');

    char    line = 0;

    while (line == getnextline(fd))
    {
        ft_putstr(line);
    }
    return (0);
 }