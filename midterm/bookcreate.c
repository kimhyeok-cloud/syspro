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
    FILE *fp = fopen("db.dat", "ab+");
    if (!fp) {
        perror("File open error");
        return 1;
    }

    Book b;

    if (scanf("%d", &b.id) != 1) {
        fclose(fp);
        return 0;
    }

    scanf(" %63s", b.name);
    scanf(" %63s", b.author);
    scanf("%d", &b.year);
    scanf("%d", &b.numofborrow);
    scanf("%d", &b.borrow);

    fwrite(&b, sizeof(Book), 1, fp);

    fclose(fp);
    return 0;
}

