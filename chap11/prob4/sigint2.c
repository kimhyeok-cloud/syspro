#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

struct sigaction newact;
struct sigaction oldact;

void sigint_handler(int signo) {
    printf("Received signal: %d\n", signo);
    exit(0);
}

int main(void) {
    newact.sa_handler = sigint_handler;
    sigfillset(&newact.sa_mask);
    newact.sa_flags = 0;

    sigaction(SIGINT, &newact, &oldact);

    while (1)
        pause();

    return 0;
}

