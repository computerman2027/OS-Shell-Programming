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
        int ppid=getppid();
        sleep(2);
        printf("child process pid = %d ppid = %d\n",getpid(),getppid());
        sleep(2);
        kill(ppid,SIGSTOP);
        sleep(5);
        kill(ppid,SIGCONT);
        sleep(2);
        kill(ppid,SIGKILL);

    }
    else
    {
        printf("Waiting for Child to Stop\n");
        int x=1;
        while(1)
        {
            printf("%d s\n",x);
            fflush(stdout);
            x++;
            sleep(1);
        }
    }
}