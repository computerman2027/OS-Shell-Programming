#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pipemodule[2];
    int returnstatus;

    returnstatus = pipe(pipemodule);

    if(returnstatus==-1)
    {
        printf("Unable to create pipe\n");
        return 0;
    }
    char writemessage[2][20] = {"hello","happy"};
    char readmessage[20];


    printf("writing message 1 = %s\n",writemessage[0]);
    if(write(pipemodule[1],writemessage[0],sizeof(writemessage[0]))==-1)
    {
        printf("message1 could not be written\n");
        return 0;
    }

    if(read(pipemodule[0],readmessage,sizeof(readmessage))==-1)
    {
        printf("message 1 could not be read\n");
        return 0;
    }
    printf("read message 1 = %s\n", readmessage);

    printf("writing message 2 = %s\n", writemessage[1]);
    if (write(pipemodule[1], writemessage[1], sizeof(writemessage[1])) == -1)
    {
        printf("message2 could not be written\n");
        return 0;
    }

    if (read(pipemodule[0], readmessage, sizeof(readmessage)) == -1)
    {
        printf("message 2 could not be read\n");
        return 0;
    }
    printf("read message 2 = %s\n", readmessage);

    close(pipemodule[0]);
    close(pipemodule[1]);

    return 0;


}