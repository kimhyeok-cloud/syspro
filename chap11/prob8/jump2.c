#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <setjmp.h>
#include <signal.h>

jmp_buf env;

void p1() {
    while (1) {
        printf("Loop\n");
        sleep(1);
    }
}

void intHandler(int sig) {
    printf("Interrupt\n");
    longjmp(env, 1);
}

int main() {
    signal(SIGINT, intHandler);

    if (setjmp(env) != 0) {
        printf("Return due to interrupt\n");
        exit(0);
    } 
    else {
        printf("First pass\n");
    }

    p1();

    return 0;
}

