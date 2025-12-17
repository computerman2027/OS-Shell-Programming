#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<time.h>

int main()
{
    int p[2];

    if(pipe(p)==-1)
    {
        printf("Pipe creation failed\n");
        return 1;
    }

    int pid =fork();
    if(pid==-1)
    {
        printf("fork failed\n");
        return 2;
    }

    if(pid==0)
    {
        close(p[1]);
        int datareceived;
        if(read(p[0],&datareceived,sizeof(datareceived))==-1)
        {
            printf("Data not read by child\n");
            return 4;
        }
        printf("Data read by child = %d",datareceived);
        close(p[0]);
    }
    else
    {
        close(p[0]);
        srand(time(NULL));
        int data = rand() % 20;
        printf("data = %d\n",data);
        if(write(p[1],&data,sizeof(data))==-1)
        {
            printf("Data not written in pipe\n");
            return 3;
        }
        close(p[1]);
    }

    return 0;
}