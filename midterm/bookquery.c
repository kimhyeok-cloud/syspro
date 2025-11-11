#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[64];
    char author[64];
    int year;
    int numofborrow;
    int borrow;
} Book;

int main() {
    FILE *fp = fopen("db.dat", "rb");
    if (!fp) {
        printf("No data file\n");
        return 0;
    }

    int mode;
    if (scanf("%d", &mode) != 1) {
        fclose(fp);
        return 0;
    }

    printf(" id  bookname     author    year  numofborrow  borrow\n");

    Book b;
    while (fread(&b, sizeof(Book), 1, fp) == 1) {
        if (mode == 0) {
            printf("%2d  %-12s %-8s %4d %6d %5s\n",
                   b.id, b.name, b.author, b.year,
                   b.numofborrow, b.borrow ? "True" : "False");
        } else if (mode == 1) {
            if (b.borrow == 0) {
                printf("%2d  %-12s %-8s %4d %6d %5s\n",
                       b.id, b.name, b.author, b.year,
                       b.numofborrow, b.borrow ? "True" : "False");
            }
        }
    }

    fclose(fp);
    return 0;
}

