#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
Crear una función que ejecute un comando en un proceso hijo y te devuelva un file descriptor conectado a:
La salida (stdout) del hijo si el type es 'r'.
La entrada (stdin) del hijo si el type es 'w'.
Tu programa (padre) podrá leer desde o escribir hacia ese proceso por medio del descriptor retornado.
*/

/*
    PASO 1: validar argumentos (si error: return -1)
    PASO 2:
        - crear una pipe (comunicar el padre y el hijo)
    PASO 3: 
        - crear un proceso hijo con fork()
        - 
*/

int	ft_popen(const char *file, char const *av[], char type)
{
    if (!file || !av || (type != 'r' && type != 'w'))
    {
        return (-1);
    }

    int	pipefd[2];
    int pid;

    if (pipe(pipefd) == -1)
    {
        exit(1);
    }
    
    pid = fork();

    if (pid < 0)
    {
        //  error creating the fork()
        printf("error creando fork()\n");
        close(pipefd[1]);
        exit(1);
    }
    if (pid == 0)  //proceso hijo
    {
        if (type == 'r')
        {
            dup2(pipefd[1], STDOUT_FILENO);
        }
        if (type == 'w') 
        {
            dup2(pipefd[0], STDIN_FILENO);
        }
        close(pipefd[0]);
        close(pipefd[1]);

        if (execvp(file, (char *const *)av) == -1)
        {
            exit(1);
        }
    }
    else    // proceso PADRE 
    {
        if (type == 'r')
        {
            close(pipefd[1]);
            return (pipefd[0]);
        }
        if (type == 'w')
        {
            close(pipefd[0]);
            return (pipefd[1]);
        }
    }
    return (0);
}

// int main(int ac, char **av)

int main(void)
{
    int fd = ft_popen("ls", (char const *[]) {"ls", "-l", NULL}, 'r');

    if (fd == -1)
    {
        write( 2, "Error in ft_popen\n", 18);
        return (1);
    }
    char    buffer[1024];
    ssize_t bytes;

    while ( (bytes = read(fd, buffer, sizeof(buffer) - 1)) > 0)
    {
        buffer[bytes] = '\0';
        write (1, buffer, bytes);
    }
    close(fd);
    return (0);
}