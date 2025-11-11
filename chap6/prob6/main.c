#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <oldfile> <newfile>\n", argv[0]);
        exit(1);
    }

    if (link(argv[1], argv[2]) == -1) {
        perror("link");
        exit(1);
    }

    printf("Hard link created: %s -> %s\n", argv[2], argv[1]);
    return 0;
}

