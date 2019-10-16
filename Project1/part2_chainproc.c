
void createChild(int i)
{
    if (fork() == 0)
    {
        printf("Hello from [child] pid %d from [parent] pid %d\n", getpid(), getppid());
        if (i > 0)
        {
            createChild(i - 1);
        }
        else
        {
            exit(0);
        }
    }
}

int main(int argc, char *argv[])
{
    int i;
    int pro = atoi(argv[1]);
    createChild(pro);
    // for ( i = 0; i < pro; i++){
    //     if (fork() == 0){
    //         printf("Hello from [child] pid %d from [parent] pid %d\n", getpid(), getppid());
    //         exit(0);
    //     }
    // }
    for (i = 0; i < pro; i++)
        wait(NULL);
}
