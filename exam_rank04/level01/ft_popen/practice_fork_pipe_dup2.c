#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//  PRACTICE FORK() COMMAND

void    exercise01_easy(void)
{
    int pipefd[2];
    int pid;

    if (pipe(pipefd) == -1)
    {
        printf("error creating pipe\n");
        exit(1);
    }
    
    pid = fork();
    if (pid < 0)
    {
        printf("error creating new process\n");
        exit(1);
    }
    else if (pid == 0)  //  child process
    {
        //  cerrramos extreme lectura
        char    message[35] = "sending message to father process ";
        close(pipefd[0]);   
        write(pipefd[1], message, strlen(message));
        //  close extreme read
        close(pipefd[1]);
    }
    else
    {
        //  main process (proceso padre)
        char    message01[100];
        int     n = read(pipefd[0], message01, sizeof(message01) - 1);
        if (n > 0)
        {
            message01[n] = '\n';
            printf("Padre recibio: %s\n", message01);
        }

        close(pipefd[1]);   //  el padre no lo usa 
        close(pipefd[0]);   //  despues de leer
    }

}

int main(void)
{
    exercise01_easy();
    return (0);
}
