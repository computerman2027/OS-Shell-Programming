#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main()
{
    
    printf("Parent PID = %d\n",getpid());

    int p= fork();
    if(p==-1)
    {
        printf("fork Unsuccessful\n");
        return 0;
    }
    else if(p==0)
    {
        int ppid1=getppid();
        printf("child process pid = %d ppid = %d\n",getpid(),getppid());
        sleep(2);
        kill(ppid1,SIGKILL);
        sleep(5);
        printf("child process pid = %d ppid = %d\n",getpid(),getppid());
        if(getppid()!=ppid1)
        {
            printf("I became orphan..\n");
        }
        else
        {
            printf("I am child..\n");
        }

    }
    else
    {
        
        while(1)
        {
            printf("Waiting for SIGKILL...\n");
            sleep(1);
        }
    }

}