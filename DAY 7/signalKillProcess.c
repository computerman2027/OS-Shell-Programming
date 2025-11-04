#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main()
{
    int pid;

    printf("Enter Pid of the process to kill : ");
    scanf("%d",&pid);

    if(kill(pid,SIGKILL)==0)
    printf("SUccessful SIGKILL \n");
    else
    printf("not SUccessful SIGKILL \n");
    return 0;
}