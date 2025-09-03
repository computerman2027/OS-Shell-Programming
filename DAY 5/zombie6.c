#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

volatile sig_atomic_t flag = 0; // <-- make it safe across signals

void handle_sigChild(int sig)
{
    int status;
    pid_t pid = wait(&status); // reap the child

    if (pid > 0)
    {
        printf("\n[Parent] Reaped child %d ", pid);
        if (WIFEXITED(status))
        {
            printf("(exit status = %d)\n", WEXITSTATUS(status));
        }
        else
        {
            printf("(did not exit normally)\n");
        }
    }
    flag = 1;
}

int main()
{
    signal(SIGCHLD, handle_sigChild);

    printf("Starter process id = %d\n", getpid());
    int p = fork();

    if (p == -1)
    {
        printf("Process not created \n");
    }
    else if (p == 0)
    {
        printf("[Child] PID = %d PPID = %d\n", getpid(), getppid());
        sleep(2);
        exit(42);
    }
    else
    {
        for (int i = 0; i < 1000000; i++)
        {
            if (flag == 1)
            {
                printf("[Parent] Child was reaped. Stopping.\n");
                sleep(10);
                exit(0);
            }
            if (i % 1 == 0)
            { // slow down output
                printf("[Parent] count = %d\n", i);
            }
        }
    }
    return 0;
}
