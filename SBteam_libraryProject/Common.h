#pragma once

#define MAX_1D          100
#define MAX_ROWS        20
#define MAX_COLS        20
#define MAX_LIST_SIZE   50
#define MAX_STACK_SIZE  50
#define MAX_QUEUE_SIZE  50
#define MAX_STRING_LEN  256

/* Cursor-based singly linked list */
struct Node {
    int data;
    Node* next;
};/* Cursor-based doubly linked list */
struct dNode {
    int data;
    dNode* prev;
    dNode* next;    
};

/* Array-based Stack */
struct Stack {
    Node* top;   // top element
};

/* Circular Array Queue */
struct Queue {
    Node* front;  // first element
    Node* rear;   // last element
    int count;
};