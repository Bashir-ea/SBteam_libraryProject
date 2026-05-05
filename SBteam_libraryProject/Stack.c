#include<stdlib.h>
#include"Stack.h"
#define SENTINEL -99999
void initStack(Stack* S) {
	S->top = NULL;
}
int push(Stack* S, int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) return 0;
	newNode->data = value;
	newNode->next = S->top;
	S->top = newNode;
	return 1;
}
int pop(Stack* S) {
	if (S->top == NULL) return SENTINEL;
	Node* temp = S->top;
	int value = temp->data;
	S->top = S->top->next;
	free(temp);
	return value;
}
int peek(Stack* S) {
	if (S->top == NULL) return SENTINEL;
	return S->top->data;
}
void display(const Stack* S) {
    if (S == NULL) return;

    const Node* cur = S->top;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void freeStack(Stack* S) {
    if (S == NULL) return;

    Node* cur = S->top;
    while (cur != NULL) {
        Node* nxt = cur->next;
        free(cur);
        cur = nxt;
    }

    S->top = NULL;
}