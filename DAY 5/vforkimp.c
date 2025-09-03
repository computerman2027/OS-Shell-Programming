#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	printf("Current process pid = %d ppid = %d\n",getpid(), getppid());
	int i=1;
	printf("parent i = %d\n",i);
	i++;
	int p = vfork();
	if(p==-1)
	{
		printf("Error occured\n");
		return 0;
	}
	if(p==0)
	{
		i++;
		printf("child i = %d\n",i);
		i++;
		printf("child i = %d\n",i);
		_exit(0);
	}
	else
	{
		printf("parent i = %d\n",i);
				
	}
	return 0;

}

