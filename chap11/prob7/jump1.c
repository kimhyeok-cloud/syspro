#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void p1();
void p2();

jmp_buf env;

int main() 
{
    if (setjmp(env) != 0) {
        printf("Exception handling after return due to error\n");
        exit(0);
    } 
    else {
        printf("First pass\n");
    }

    p1();

    return 0;
}

void p1() {
    printf("In p1, calling p2\n");
    p2();
    printf("This line in p1 will not be executed if p2 raises error\n");
}

void p2() {
    printf("In p2, raising an error\n");
    longjmp(env, 1);
}

