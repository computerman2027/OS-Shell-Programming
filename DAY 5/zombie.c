#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	printf("Current process pid = %d ppid = %d\n",getpid(), getppid());

	int p = fork();
	
	if(p==-1)
	{
		printf("Error occured \n");
		return 0;
	}
	if(p==0)
	{
		printf("Child process pid = %d ppid = %d\n",getpid(), getppid());
		exit(0);
	}
	else
	{
		printf("parent process before sleep pid = %d ppid = %d\n",getpid(), getppid());
		sleep(60);
		printf("parent process after sleep pid = %d  ppid = %d\n",getpid(), getppid());
	}

	return 0;

}

