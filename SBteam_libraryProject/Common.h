#pragma once

#define MAX_1D          100
#define MAX_ROWS        20
#define MAX_COLS        20
#define MAX_LIST_SIZE   50
#define MAX_STACK_SIZE  50
#define MAX_QUEUE_SIZE  50
#define MAX_STRING_LEN  256

/* Cursor-based singly linked list */
struct ArrayList {
    int data[MAX_LIST_SIZE];
    int next[MAX_LIST_SIZE];   // next[i] = index of successor, -1 = end
    int head;                   // index of first element, -1 = empty
    int size;
};/* Cursor-based doubly linked list */
struct DLL {
    int data[MAX_LIST_SIZE];
    int next[MAX_LIST_SIZE];
    int prev[MAX_LIST_SIZE];
    int head;
    int tail;
    int size;
};

/* Array-based Stack */
struct Stack {
    int data[MAX_STACK_SIZE];
    int top;    // index of topmost element, -1 = empty
};

/* Circular Array Queue */
struct Queue {
    int data[MAX_QUEUE_SIZE];
    int front;  // index of front element
    int rear;   // index of last element
    int count;  // number of elements
};