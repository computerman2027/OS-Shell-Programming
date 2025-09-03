#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handle_sigChild(int sig)
{
    printf("\nMessage from parent that tyhe child has been killed\n");
    exit(0);
}

int main()
{
    signal(SIGCHLD, handle_sigChild);

    printf("Starter process id = %d\n",getpid());
    int p=fork();

    if(p==-1)
    {
        printf("Process not created \n");
    }
    else if(p==0)
    {
        printf("child process. PID = %d PPID = %d\n",getpid(), getppid());
    }
    else
    {
        int i;
        for(i=0;i<1000000;i++)
        {
            printf("%d ",i);
        }
    }

    return 0;
}