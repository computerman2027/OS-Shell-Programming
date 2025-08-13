#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int p;
    p = fork();
    if (p == 0)
    {
        printf("Child id : %d\n", getpid());
        printf("Parent id : %d", getppid());
    }

    return 0;
}