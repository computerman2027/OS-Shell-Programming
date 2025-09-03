#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid = fork();

    if (pid == 0)
    {
        printf("Child process: PID = %d\n", getpid());
        exit(0); 
    }
    else
    {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        sleep(20); // Sleep long enough to see zombie in `ps`
    }

    return 0;
}
