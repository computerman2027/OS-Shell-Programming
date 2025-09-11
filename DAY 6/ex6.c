#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char* tem[4];
    tem[0] = "./c";
    tem[1] = "hello";
    tem[2] = "world";
    tem[3] = NULL;

    printf("I am parent pid %d\n", getpid());
    system("gcc ex.c -o c");

    char* envp[] = {
        "MYVAR=TestEnvironmentVariable",
        NULL
    };

    execve(tem[0], tem, envp);

    printf("This line will NOT be printed if execle succeeds\n");

    return 0;
}
