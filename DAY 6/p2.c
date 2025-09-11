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
        char* temp[3];
	    temp[0]= "pwd";
	    temp[1]= (char*)0;

        sleep(1);

        printf("I am parent pid %d\n",getpid());
        printf("pwd : ");
	    fflush(stdout);
	    execv("/bin/pwd",temp);
	
	    printf("This line will not be printed \n");

    }
    else
    {
        printf("This is parent\n");
        sleep(5);
        exit(0);
    }
}