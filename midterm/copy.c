#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *src, *dest;
    int ch, option;

    if (argc != 4) {
        printf("Usage: %s <option> <source> <destination>\n", argv[0]);
        printf("Options:\n  1 - Convert to lowercase\n  2 - Convert to uppercase\n");
        return 1;
    }

    option = atoi(argv[1]);

    src = fopen(argv[2], "r");
    if (src == NULL) {
        perror("Source file open error");
        return 1;
    }

    dest = fopen(argv[3], "w");
    if (dest == NULL) {
        perror("Destination file open error");
        fclose(src);
        return 1;
    }

    while ((ch = fgetc(src)) != EOF) {
        if (option == 1)
            ch = tolower(ch);
        else if (option == 2)
            ch = toupper(ch);
        fputc(ch, dest);
    }

    fclose(src);
    fclose(dest);

    dest = fopen(argv[3], "r");
    if (dest == NULL) {
        perror("Result file open error");
        return 1;
    }

    printf("Result (%s):\n", argv[3]);
    while ((ch = fgetc(dest)) != EOF)
        putchar(ch);

    fclose(dest);
    return 0;
}



	


