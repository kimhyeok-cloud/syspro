#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

extern char **environ;  // 환경변수 목록 접근

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s [options]\n", argv[0]);
        printf("Options:\n");
        printf("  -e [VAR]   Show environment variable (all if VAR not given)\n");
        printf("  -u         Show real/effective user ID\n");
        printf("  -g         Show real/effective group ID\n");
        printf("  -i         Show process ID\n");
        printf("  -p         Show parent process ID\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                char *value = getenv(argv[i + 1]);
                if (value)
                    printf("%s=%s\n", argv[i + 1], value);
                else
                    printf("Environment variable '%s' not found.\n", argv[i + 1]);
                i++;
            } else {
                for (char **env = environ; *env != NULL; env++)
                    printf("%s\n", *env);
            }
        } 
        else if (strcmp(argv[i], "-u") == 0) {
            printf("Real User ID: %d (%s)\n", getuid(), getpwuid(getuid())->pw_name);
            printf("Effective User ID: %d (%s)\n", geteuid(), getpwuid(geteuid())->pw_name);
        } 
        else if (strcmp(argv[i], "-g") == 0) {
            printf("Real Group ID: %d (%s)\n", getgid(), getgrgid(getgid())->gr_name);
            printf("Effective Group ID: %d (%s)\n", getegid(), getgrgid(getegid())->gr_name);
        } 
        else if (strcmp(argv[i], "-i") == 0) {
            printf("Process ID: %d\n", getpid());
        } 
        else if (strcmp(argv[i], "-p") == 0) {
            printf("Parent Process ID: %d\n", getppid());
        } 
        else {
            printf("Unknown option: %s\n", argv[i]);
        }
    }

    return 0;
}

