#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile int done = 0;

void alarmHandler(int sig) {
    printf("Alarm received!\n");
    done = 1;
}

int main() {
    signal(SIGALRM, alarmHandler);
    alarm(5);

    short i = 0;
    while (!done) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }

    printf("end\n");
    return 0;
}

