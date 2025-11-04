#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include <sys/wait.h>
#include <time.h>
#include<string.h>

void handle_sigInt(int sig)
{
    printf("Stop not allowed\n");
}

int main()
{
    struct sigaction act;
    memset(&act, 0, sizeof(struct sigaction));
    act.sa_flags = SA_RESETHAND;
    act.sa_handler = &handle_sigInt;
    sigaction(SIGINT, &act, NULL);

    
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