#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[20];
    struct student *next;
};

int main() {
    int id;
    char name[20];
    struct student *p, *head = NULL;

    printf("Enter student ID and name (non-integer ID to stop):\n");

    while (scanf("%d %19s", &id, name) == 2) {
        p = (struct student *)malloc(sizeof(struct student));
        if (p == NULL) {
            perror("malloc");
            return 1;
        }
        p->id = id;
        strcpy(p->name, name);

        p->next = head;
        head = p;
    }

    printf("\n* Student Information (Reversed Order) *\n");
    for (p = head; p != NULL; p = p->next) {
        printf("%d %s\n", p->id, p->name);
    }

    return 0;
}

