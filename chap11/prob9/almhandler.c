#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

typedef void (*sighandler_t)(int);

sighandler_t my_signal(int signo, sighandler_t handler) {
    struct sigaction act, oldact;
    act.sa_handler = handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (sigaction(signo, &act, &oldact) < 0) {
        perror("sigaction error");
        exit(1);
    }
    return oldact.sa_handler;
}

void alarmHandler(int sig) {
    printf("Alarm signal received. Exiting.\n");
    exit(0);
}

int main() {
    short i = 0;
    my_signal(SIGALRM, alarmHandler);
    alarm(5);

    while (1) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }

    printf("end\n");
    return 0;
}

