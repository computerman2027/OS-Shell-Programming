#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

void main()
{
	char* tem[4];
	tem[0]= "./c";
	tem[1] = "hello";
	tem[2] = "world";
	tem[3]= (char*)0;
	
	printf("I am parent pid %d\n",getpid());

	system("gcc ex.c -o c");
	execlp(tem[0],tem[0],tem[1],tem[2],tem[3]);
	
	printf("This line will not be printed \n");
}
