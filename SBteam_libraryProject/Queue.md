Function: initQueue

Problem Understanding

    Input: Q — pointer to a Queue structure (output parameter: its fields will be set)
    Output: sets Q->front = NULL and Q->rear = NULL (queue becomes logically empty)
    Edge cases: Q == NULL (function returns immediately; caller should pass a valid pointer)

Algorithm

    Set Q->front to NULL
    Set Q->rear to NULL

Function: enqueue

Problem Understanding

    Input: Q — pointer to a Queue, value — integer to insert at the rear
    Output: adds a new node containing value to the rear of the queue; returns value on success, -1 on failure
    Edge cases:
        Q == NULL (returns -1)
        memory allocation fails (returns -1)
        queue is empty (Q->rear == NULL): new node becomes both front and rear

Algorithm

    If Q is NULL, return -1
    Allocate a new node
        If allocation fails, return -1
    Set newNode->data = value, newNode->next = NULL
    If queue is empty (Q->rear == NULL)
        Set Q->front = newNode
        Set Q->rear = newNode
    Else
        Set Q->rear->next = newNode
        Set Q->rear = newNode
    Return value

Function: dequeue

Problem Understanding

    Input: Q — pointer to a Queue
    Output: removes the front node from the queue and returns its stored value; returns -1 if the queue is empty/failure
    Edge cases:
        Q == NULL (returns -1)
        queue is empty (Q->front == NULL) (returns -1)
        removing the last element: after removal Q->front becomes NULL, so Q->rear must also be set to NULL

Algorithm

    If Q is NULL or Q->front is NULL, return -1
    Store the current front node in a temporary pointer
    Save its data to return later
    Move Q->front to Q->front->next
    If Q->front is now NULL (queue became empty)
        Set Q->rear = NULL
    Free the removed node
    Return the saved value

Function: front

Problem Understanding

    Input: Q — pointer to a Queue
    Output: returns the value stored at the front of the queue (peek); returns -1 if empty/failure
    Edge cases:
        Q == NULL (returns -1)
        Q->front == NULL (queue empty → returns -1)
        returning -1 is ambiguous if -1 is a valid queue value (API limitation)

Algorithm

    If Q is NULL or Q->front is NULL, return -1
    Return Q->front->data

Function: rear

Problem Understanding

    Input: Q — pointer to a Queue
    Output: returns the value stored at the rear of the queue (peek); returns -1 if empty/failure
    Edge cases:
        Q == NULL (returns -1)
        Q->rear == NULL (queue empty → returns -1)
        returning -1 is ambiguous if -1 is a valid queue value (API limitation)

Algorithm

    If Q is NULL or Q->rear is NULL, return -1
    Return Q->rear->data
