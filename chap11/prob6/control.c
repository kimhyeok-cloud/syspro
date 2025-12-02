#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

pid_t pid1, pid2;

void alarmHandler(int sig) {
    printf("Alarm signal received. Terminating children.\n");
    kill(pid1, SIGINT);
    kill(pid2, SIGINT);
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <N seconds>\n", argv[0]);
        exit(1);
    }

    int limit;
    sscanf(argv[1], "%d", &limit);
    signal(SIGALRM, alarmHandler);
    alarm(limit);

    int count1 = 0, count2 = 0;

    pid1 = fork();
    if (pid1 == 0) {
        while (1) {
            sleep(1);
            printf("child [1] execute: %d\n", ++count1);
        }
    }

    pid2 = fork();
    if (pid2 == 0) {
        while (1) {
            sleep(1);
            printf("child [2] execute: %d\n", ++count2);
        }
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}

