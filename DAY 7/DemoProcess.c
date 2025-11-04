#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("PID = %d\n",getpid());
    while(1)
    {
        printf("hello\n");
        fflush(stdout);
        sleep(1);
    }

    return 0;

}