#pragma once
#pragma once 
#ifndef STACK_H
#define STACK_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;


typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* S);
int isEmpty(const Stack* S);
int push(Stack* S, int value);
int pop(Stack* S, int* value);
void display(const Stack* S);
void freeStack(Stack* S);

#endif
