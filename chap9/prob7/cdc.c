#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX 1024

void run_command(char *cmd);

int main() {
    char line[MAX];

    while (1) {
        printf("shell> ");
        fflush(stdout);

        if (fgets(line, MAX, stdin) == NULL)
            break;

        line[strcspn(line, "\n")] = 0;

        char *token = strtok(line, ";");

        while (token != NULL) {
            run_command(token);
            token = strtok(NULL, ";");
        }
    }

    return 0;
}

void run_command(char *cmd) {
    char *args[50];
    char temp[MAX];
    int background = 0;
    int fd;

    strcpy(temp, cmd);

    char *p = strchr(temp, '&');
    if (p != NULL) {
        background = 1;
        *p = '\0';
    }

    p = strchr(temp, '>');
    if (p != NULL) {
        *p = '\0';
        p++;
        while (*p == ' ') p++;
        char *outfile = p;

        fd = open(outfile, O_CREAT | O_TRUNC | O_WRONLY, 0660);
        dup2(fd, STDOUT_FILENO);
        close(fd);
    }

    p = strchr(temp, '<');
    if (p != NULL) {
        *p = '\0';
        p++;
        while (*p == ' ') p++;
        char *infile = p;

        fd = open(infile, O_RDONLY);
        dup2(fd, STDIN_FILENO);
        close(fd);
    }

    int i = 0;
    char *arg = strtok(temp, " ");
    while (arg != NULL) {
        args[i++] = arg;
        arg = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (args[0] == NULL)
        return;

    int pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        perror("exec");
        exit(1);
    }

    if (!background)
        wait(NULL);
}

