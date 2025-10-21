#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) 
{
    char buffer[BUFSIZE];
    int fd;
    ssize_t nread;
    long total = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("File open error");
        exit(1);
    }

    while ((nread = read(fd, buffer, BUFSIZE)) > 0) {
        total += nread;
    }

    if (nread == -1) {
        perror("Read error");
        close(fd);
        exit(1);
    }

    close(fd);
    printf("%s File size: %ld Bytes\n", argv[1], total);
    return 0;
}

