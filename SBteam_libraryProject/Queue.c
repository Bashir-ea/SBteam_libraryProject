#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include <stdlib.h>

void initQueue(Queue* Q) {
    if (Q == NULL) return;
    Q->front = NULL;
    Q->rear = NULL;
}

int enqueue(Queue* Q, int value) {
    if (Q == NULL) return -1;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return -1;

    newNode->data = value;
    newNode->next = NULL;

    if (Q->rear == NULL) {          /* queue is empty */
        Q->front = newNode;
        Q->rear = newNode;
    }
    else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }

    return value;
}

int dequeue(Queue* Q) {
    if (Q == NULL || Q->front == NULL) return -1;

    Node* oldFront = Q->front;
    int val = oldFront->data;

    Q->front = oldFront->next;
    if (Q->front == NULL) {         /* became empty */
        Q->rear = NULL;
    }

    free(oldFront);
    return val;
}

int front(Queue* Q) {
    if (Q == NULL || Q->front == NULL) return -1;
    return Q->front->data;
}

int rear(Queue* Q) {
    if (Q == NULL || Q->rear == NULL) return -1;
    return Q->rear->data;
}
