/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sandbox.c                                          :+:      :+:    :+:   */
/*                                                    ft +:+         +:+     */
/*   By: dasalaza <dasalaza@student.42barcelona.c>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:18 by dasalaza          #+#    #+#             */
/*   Updated: 2024/10/15 16:24:07 by dasalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>     // fork(), alarm(), _exit()
#include <sys/wait.h>   // waitpid(), WIFEXITED, WIFSIGNALED, WEXITSTATUS, WTERMSIG
#include <signal.h>     // sigaction, SIGALRM, SIGKILL, struct sigaction
#include <stdbool.h>    // bool
#include <stdio.h>      // printf()
#include <stdlib.h>     // exit()
#include <errno.h>      // errno, EINTR
#include <string.h>     // strsignal()

// Handler vide pour interrompre waitpid() sur SIGALRM
static void do_nothing(int sig)
{
    (void)sig;
}

int sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
    pid_t pid = fork();
    if (pid < 0)
        return -1;

    if (pid == 0)
    {
        // --- Processus enfant ---
        alarm(timeout);
        f();
        _exit(0);
    }

    // --- Processus parent ---
    struct sigaction sa = {0};
    sa.sa_handler = do_nothing;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGALRM, &sa, NULL) < 0)
        return -1;

    alarm(timeout);

    int status;
    pid_t r = waitpid(pid, &status, 0);
    if (r < 0)
    {
        if (errno == EINTR)
        {
            // Timeout : kill et récolte de l'enfant
            kill(pid, SIGKILL);
            waitpid(pid, NULL, 0);
            if (verbose)
                printf("Bad function: timed out after %u seconds\n", timeout);
            return 0;
        }
        return -1;
    }

    // Annuler l'alarme restante
    alarm(0);

    if (WIFEXITED(status))
    {
        int code = WEXITSTATUS(status);
        if (code == 0)
        {
            if (verbose)
                printf("Nice function!\n");
            return 1;
        }
        if (verbose)
            printf("Bad function: exited with code %d\n", code);
        return 0;
    }

    if (WIFSIGNALED(status))
    {
        int sig = WTERMSIG(status);
        if (sig == SIGALRM)
        {
            if (verbose)
                printf("Bad function: timed out after %u seconds\n", timeout);
        }
        else
        {
            if (verbose)
                printf("Bad function: %s\n", strsignal(sig));
        }
        return 0;
    }

    // Cas imprévu
    return -1;
}