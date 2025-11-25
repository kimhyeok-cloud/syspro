#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        perror("malloc");
        exit(1);
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct node **top) {
    struct node *temp;
    int value;

    if (*top == NULL) {
        printf("Stack is empty.\n");
        return -1;
    }

    temp = *top;
    value = temp->data;
    *top = temp->next;
    free(temp);

    return value;
}

int main() {
    struct node *top = NULL;
    int value;

    printf("Enter natural numbers to push. Enter a non-natural value to stop:\n");

    while (scanf("%d", &value) == 1 && value > 0) {
        push(&top, value);
    }

    printf("\nStack (Top to Bottom):\n");
    while (top != NULL) {
        printf("%d\n", pop(&top));
    }

    return 0;
}

