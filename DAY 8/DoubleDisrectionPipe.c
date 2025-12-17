#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

    int p1[2]; // P-> C
    int p2[2]; // c-> P
    if (pipe(p1) == -1)
    {
        printf("pipe 1 could not be created\n");
        return 1;
    }

    if (pipe(p2) == -1)
    {
        printf("pipe 2 could not be created\n");

        return 2;
    }
    int pid = fork();

    if (pid == -1)
    {
        printf("fork failed \n");
        return 3;
    }
    if (pid == 0)
    {
        close(p1[1]);
        close(p2[0]);
        int x;
        if (read(p1[0], &x, sizeof(x)) == -1)
        {
            printf("Reading from pipe 1 failed by child\n");
            return 4;
        }

        printf("Received %d\n", x);
        x *= 10;

        if (write(p2[1], &x, sizeof(x)) == -1)
        {
            printf("writing in pipe 2 failed by child\n");
            return 5;
        }

        printf("Wrote from child %d\n", x);

        close(p1[0]);
        close(p2[1]);
    }
    else
    {
        close(p1[0]);
        close(p2[1]);
        srand(time(NULL));
        int y = rand() % 20;
        if (write(p1[1], &y, sizeof(y)) == -1)
        {
            printf("writing in pipe 1 failed by parent\n");

            return 6;
        }

        printf("Wrote %d\n", y);

        if (read(p2[0], &y, sizeof(y)) == -1)
        {
            printf("reading from pipe 2 failed by parent\n");

            return 7;
        }

        printf("Result is %d\n", y);
        close(p1[1]);
        close(p2[0]);
        wait(NULL);
    }
    close(p1[0]);
    close(p1[1]);
    return 0;
}