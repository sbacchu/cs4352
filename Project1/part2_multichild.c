#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int pro = atoi(argv[1]);
    int i;
    for ( i = 0; i < pro; i++){
        if (fork() == 0){
            printf("Hello from [child] pid %d from [parent] pid %d\n", getpid(), getppid());
            exit(0);
        }
    }
    for ( i = 0; i < pro; i++)
        wait(NULL);
}
