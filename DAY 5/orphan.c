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
	if(p>1)
	{
		printf("Parent process pid = %d ppid = %d\n",getpid(), getppid());
		sleep(10);
		exit(0);
	}
	else
	{
		printf("child process before sleep pid = %d ppid = %d\n",getpid(), getppid());
		sleep(30);
		printf("child process after sleep pid = %d  ppid = %d\n", getpid(), getppid());
		// sleep(30);
		// printf("child process after sleep pid = %d  ppid = %d\n", getpid(), getppid());
	}

	return 0;

}

