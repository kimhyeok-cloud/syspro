#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void addq(struct node **head, struct node **tail, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        perror("malloc");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*tail == NULL) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

int delete(struct node **head, struct node **tail) {
    struct node *temp;
    int value;

    if (*head == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }

    temp = *head;
    value = temp->data;

    *head = temp->next;
    if (*head == NULL)
        *tail = NULL;

    free(temp);
    return value;
}

int main() {
    struct node *head = NULL;
    struct node *tail = NULL;
    int value;

    printf("Enter natural numbers to enqueue. Enter non-natural to stop:\n");

    while (scanf("%d", &value) == 1 && value > 0) {
        addq(&head, &tail, value);
    }

    printf("\nQueue (Front to Rear):\n");
    while (head != NULL) {
        printf("%d\n", delete(&head, &tail));
    }

    return 0;
}

