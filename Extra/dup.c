#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int p = fork();

    if(p==-1)
    {
        printf("error occured in creating child");
        return 1;
    }

    if(p==0)
    {

        // Open a file "pingResults.txt" for writing
        // The returned file descriptor 'file' will point to that file
        int file = open("pingResults.txt", O_WRONLY | O_CREAT, 0777);

        // File permission = requested permissions - umask
        // default umask = 0022. can be checked by typing umask in terminal

        printf("the file descriptor to pingResuls : %d\n", file);

        if (file == -1)
        {
            return 2;
        }

        // Duplicate the file descriptor 'file' using dup()
        // Now 'file2' also points to the same underlying file as 'file'
        int file2 = dup(file);

        printf("the duplicate file descriptor to pingResuls : %d\n", file2);

        if (file2 == -1)
        {
            return 2;
        }

        // BEFORE

        // file descriptors        file 
        // 0                       STDIN 
        // 1                       STDOUT 
        // 2                       STDERR 
        // 3                       pingResults.txt 
        // 4                       pingResults.txt

        // Redirect standard output (fd=1) to point to 'file'
        // After this, anything printed to stdout will go to pingResults.txt
        dup2(file, STDOUT_FILENO);

        // AFTER

        // file descriptors        file
        // 0                       STDIN
        // 1                       pingResults.txt
        // 2                       STDERR
        // 3                       pingResults.txt
        // 4                       pingResults.txt

        // We don’t need the original fd anymore; closing it is safe
        close(file);

        

        // Replace current process image with "ping"

        int err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
        if(err == -1)
        {
            printf("could not find program to execute\n");
            return 3;
        }
        printf("Thsi is not printed\n");
    }
    else
    {
        int wstatus;

        wait(&wstatus);

        if (WIFEXITED(wstatus))
        {
            int statuscode = WEXITSTATUS(wstatus);

            if(statuscode==0)
            {
                printf("Success!\n");
            }
            else
            {
                printf("Failure wih satus code %d\n",statuscode);
            }
        }
        // printf("success\n");
        printf("program complete\n");
    }

    return 0;
}
