#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include <sys/wait.h>
#include <time.h>

void handle_sigInt(int sig)
{
    printf("Stop not allowed\n");
}

int main()
{
    signal(SIGINT,handle_sigInt);
    int x = 1;
    
    while(x<=5)
    {
        printf("%d s\n", x);
        x++;
        sleep(1);
    }
    printf("Exited On My Own\n");
    return 0;
}