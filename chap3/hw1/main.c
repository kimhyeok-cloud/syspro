#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "copy.h"

#define SIZE 5
#define MAX_LEN 100

int main() {
    char buffer[MAX_LEN];
    char* sentences[SIZE];
    int count = 0;


    while (count < SIZE) {
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        sentences[count] = copy(buffer);
        count++;
    }

    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            if (strlen(sentences[i]) < strlen(sentences[j])) {
                char* temp = sentences[i];
                sentences[i] = sentences[j];
                sentences[j] = temp;
            }
        }
    }


    for (int i = 0; i < SIZE; i++) {
        printf("%s\n", sentences[i]);
        free(sentences[i]);
    }

    return 0;
}

