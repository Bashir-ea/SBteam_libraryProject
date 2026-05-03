#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* S)
{
    S->top = NULL;
}

int isEmpty(Stack* S)
{
    return (S->top == NULL);
}

void push(Stack* S, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = S->top;
    S->top = newNode;
}

int pop(Stack* S)
{
    if (isEmpty(S)) {
        printf("Stack is empty\n");
        return -1;
    }

    Node* temp = S->top;
    int value = temp->data;

    S->top = temp->next;
    free(temp);

    return value;
}

void display(Stack* S)
{
    Node* current = S->top;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main()
{
    Stack S;
    initStack(&S);

    push(&S, 10);
    push(&S, 20);
    push(&S, 30);

    printf("Stack elements:\n");
    display(&S);

    printf("Popped: %d\n", pop(&S));

    printf("After pop:\n");
    display(&S);

    return 0;
}