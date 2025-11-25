#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid1, pid2, child, status;

    printf("[%d] parent process started\n", getpid());
    pid1 = fork();
    if (pid1 == 0) {
        printf("[%d] child process #1 started\n", getpid());
        sleep(1);
        printf("[%d] child process #1 ended\n", getpid());
        exit(1);
    }

    pid2 = fork();
    if (pid2 == 0) {
        printf("[%d] child process #2 started\n", getpid());
        sleep(2);
        printf("[%d] child process #2 ended\n", getpid());
        exit(2);
    }

    child = waitpid(pid1, &status, 0);
    printf("[%d] child process #1 %d ended\n", getpid(), child);
    printf("\texit code %d\n", status >> 8);

    return 0;
}

