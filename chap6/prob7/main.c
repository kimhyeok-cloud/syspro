#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 

int main(int argc, char *argv[])
{
    if (argc != 2) { 
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    if (unlink(argv[1]) == -1) {
        perror(argv[1]);
        exit(1);
    }

    printf("File '%s' deleted successfully.\n", argv[1]);
    return 0;
}

