#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pid = fork();

    if(pid ==-1)
    {
        printf("Child process not created\n");
        exit(1);
    }

    if(pid==0)
    {
       

sleep(5);
            printf("I am parent pid %d\n",getpid());
	
	    execlp("ping","ping", "-c","5","google.com",NULL);
	
	    printf("This line will not be printed \n");

    }
    else
    {
        printf("This is parent\n");
        sleep(30);
    }
}