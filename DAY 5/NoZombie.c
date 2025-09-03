#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

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
		sleep(10);
		printf("Child process pid = %d ppid = %d\n",getpid(), getppid());;
	}
	else
	{
		printf("parent before sleep  pid = %d ppid = %d\n",getpid(), getppid());
		sleep(30);
		printf("parent after sleep  pid = %d ppid = %d\n",getpid(), getppid());
		wait(NULL);
		printf("parent after wait pid = %d ppid = %d\n",getpid(), getppid());
		sleep(10);
	}

	return 0;

}

