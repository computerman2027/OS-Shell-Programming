#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	printf("Current process pid = %d ppid = %d\n",getpid(), getppid());
	int i;
	int p = fork();
	
	if(p==0)
	{
		//printf("Child process pid = %d ppid = %d\n",getpid(), getppid());
		for(i=0;i<200;i++)
		{
			printf("child process : %d\n",i);
		}
	}
	else
	{
		//printf("parent pid = %d ppid = %d\n",getpid(), getppid());
		for(i=200;i<400;i++)
		{
			printf("parent process : %d\n",i);
		}
	}

	return 0;

}

