#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    printf("I am child after execle, pid %d\n", getpid());
    printf("Child is %s and its arguments are %s %s\n", argv[0], argv[1], argv[2]);

    // Access the environment variable
    char* env_var = getenv("MYVAR");
    if (env_var != NULL)
    {
        printf("Environment Variable MYVAR: %s\n", env_var);
    }
    else
    {
        printf("Environment Variable MYVAR not found\n");
    }

    printf("Exec end\n");
    return 0;
}
     