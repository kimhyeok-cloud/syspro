#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;

    printf("[Parent Process] PID: %d\n", getpid());

    pid = fork();

    if (pid > 0) {
        printf("[Parent Process] Child PID: %d (return value: %d)\n", pid, pid);
    } 
    else if (pid == 0) {
        printf("[Child Process] PID: %d (return value: %d)\n", getpid(), pid);
    } 
    else {
        printf("fork failed\n");
    }

    return 0;
}

