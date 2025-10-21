#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    fd = open(argv[1], O_RDWR);
    if (fd == -1) {
        perror("open");              
        fprintf(stderr, "File Open Error: %s\n", argv[1]);
        return 1;
    } else {
        printf("file %s opened successfully: fd=%d\n", argv[1], fd);
    }

    close(fd);
    return 0;
}




