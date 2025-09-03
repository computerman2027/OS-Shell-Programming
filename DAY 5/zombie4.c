#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int flag =0;

void handle_sigChild(int sig)
{
    printf("\nMessage from parent that the child has been killed\n");
    flag=1;
    // exit(0);
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
        for (i = 0; i < 1000000; i++)
        {
            if(flag==1)
            {
                printf("Child died. send SIGCHILD signal to parent. Parent stopping\n");
                sleep(10);
                exit(0);
            }
            if (i % 100 == 0)
            {
                printf("parent count = %d\n", i);
            }
        }
        if (flag == 1)
        {
            printf("Child died. send SIGCHILD signal to parent. Parent stopping\n");
            exit(0);
        }
    }

    return 0;
}