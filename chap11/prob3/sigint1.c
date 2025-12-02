#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void intHandler(int sig) {
    printf("Received signal: %d\n", sig);
}

void alarmHandler(int sig) {
    printf("Alarm signal %d received. Exiting.\n", sig);
    exit(0);
}

int main() {
    signal(SIGINT, intHandler);
    signal(SIGALRM, alarmHandler);

    alarm(10); // 10초 후 SIGALRM 발생

    while (1)
        pause();

    return 0;
}

