#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "copy.h"

char* copy(const char* src) {
    char* dest = (char*)malloc(strlen(src) + 1);
    if (dest == NULL) {
        exit(1);
    }
    strcpy(dest, src);
    return dest;
}

