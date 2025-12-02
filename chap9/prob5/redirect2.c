#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int child, pid, fd, status;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <command> [args...]\n", argv[0]);
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0660);
        if (fd < 0) {
            perror("open");
            return 1;
        }

        dup2(fd, STDOUT_FILENO);
        close(fd);

        execvp(argv[2], &argv[2]);

        fprintf(stderr, "%s: cannot execute\n", argv[2]);
        return 1;

    } else if (pid > 0) {
        child = wait(&status);
        printf("[%d] child process %d terminated\n", getpid(), child);

    } else {
        perror("fork");
        return 1;
    }

    return 0;
}

