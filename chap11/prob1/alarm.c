#include <stdio.h>
#include <unistd.h>
#include <signal.h>

volatile int done = 0;

void alarm_handler(int sig) {
    printf("Alarm received!\n");
    done = 1;  // 루프 종료 신호
}

int main() {
    signal(SIGALRM, alarm_handler);
    alarm(5);

    printf("Loop start\n");
    short i = 0;
    while (!done) {
        sleep(1);
        i++;
        printf("%d second\n", i);
    }

    printf("end\n");
    return 0;
}

