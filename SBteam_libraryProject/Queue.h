#pragma once 
#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
} Queue;

void initQueue(Queue* Q);
int enqueue(Queue* Q, int value);
int dequeue(Queue* Q);
int front(Queue* Q);
int rear(Queue* Q);


#endif
#pragma once 
#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
	int data;
	struct Node* next;
} Node;

typedef struct {
	Node* front;
	Node* rear;
} Queue;

void initQueue(Queue* Q);
int enqueue(Queue* Q, int value);
int dequeue(Queue* Q);
int front(Queue* Q);
int rear(Queue* Q);


#endif
