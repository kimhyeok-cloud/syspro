#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 1024
#define MAXARG 64

int main() {
    char line[MAX];
    char *args[MAXARG];
    char *token;
    char *saveptr;

    while (1) {
        printf("Shell> ");
        fflush(stdout);

        if (fgets(line, MAX, stdin) == NULL)
            break;

        line[strcspn(line, "\n")] = 0;  // 개행 제거

        int background = 0;
        if (line[strlen(line)-1] == '&') {
            background = 1;
            line[strlen(line)-1] = '\0';  // & 제거
        }

        // strtok_r로 공백 단위로 분리
        int i = 0;
        token = strtok_r(line, " ", &saveptr);
        while (token != NULL && i < MAXARG-1) {
            args[i++] = token;
            token = strtok_r(NULL, " ", &saveptr);
        }
        args[i] = NULL;

        if (args[0] == NULL)
            continue;  // 빈 명령어

        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            continue;
        }

        if (pid == 0) {  // 자식 프로세스
            execvp(args[0], args);
            perror("exec");
            exit(1);
        } else {  // 부모 프로세스
            if (!background)
                waitpid(pid, NULL, 0);  // 전면 실행이면 기다림
        }
    }

    return 0;
}

