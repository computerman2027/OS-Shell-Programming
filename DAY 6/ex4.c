#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>

void main()
{
	char* tem[4];
	// tem[0]= "/home/exam/CSE39/LAB PROGRAM/c";
	tem[0] = "/home/ins/5th sem/OS-Shell-Programming/DAY 5/c";
	tem[1] = "hello";
	tem[2] = "world";
	tem[3]= (char*)0;
	
	printf("I am parent pid %d\n",getpid());

	system("gcc ex.c -o c");
	execv(tem[0],tem);
	
	printf("This line will not be printed \n");
}
