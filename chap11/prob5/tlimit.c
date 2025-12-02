#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int pid;

void alarmHandler(int sig) {
    printf("[alarm] child process %d time out\n", pid);
    kill(pid, SIGINT);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <limit_sec> <command> [args...]\n", argv[0]);
        exit(1);
    }

    int limit, status;
    signal(SIGALRM, alarmHandler);
    sscanf(argv[1], "%d", &limit);
    alarm(limit);

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        execvp(argv[2], &argv[2]);
        fprintf(stderr, "%s: Cannot execute\n", argv[2]);
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        printf("[%d] child process %d exit\n", getpid(), pid);
    }

    return 0;
}

