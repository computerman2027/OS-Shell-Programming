#include<stdio.h>
#include<unistd.h>

void main(int argc, char* argv[])
{
	printf("I am child after execvp pid %d \n",getpid());
	printf("Child is %s and its arguments are %s %s\n",argv[0],argv[1], argv[2]);
	printf("Exec end\n");
}
