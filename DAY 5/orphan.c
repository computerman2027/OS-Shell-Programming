#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Starter id = %d parent = %d\n", getpid(), getppid());

    int p = fork();

    printf("p = %d\n",p);

    if(p==-1)
    {
        printf("fork failed\n");
        exit(0);
    }
    else if (p==0)
    {
        int processid = getpid();
        int parentprocessid = getppid();
        printf("This is child. PID = %d PPID = %d\n",processid, parentprocessid);
        sleep(5);
        int parentprocessid2 = getppid();
        printf("This is child after sleep. PID = %d PPID = %d\n", processid, parentprocessid2);
        if(parentprocessid!=parentprocessid2)
        {
            printf("The child became orphan\n");
        }
        else
        {
            printf("The child is normal process\n");
        }
    }
    else
    {
        printf("Parent PID = %d child = %d\n",getpid(),p);
        sleep(1);
        printf("Exit\n");
    }

    
    return 0;
}