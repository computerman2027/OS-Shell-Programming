#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	printf("staring pid = %d ppid = %d\n",getpid(),getppid());
	int count =0;
	while(1)
	{
		int p = fork();
		if(p==0)
		{
			sleep(300);
			//printf("pid = %d\n",getpid());
		}
		else if(p==-1)
		{
			printf("Count = %d \n",count);
			exit(0);
		}
		else
		{
			count++;
		}
		
	}
	

	return 0;

}

