Function: initStack

Problem Understanding

    Input: S — pointer to a Stack structure (output parameter: its fields will be set)
    Output: sets S->top = NULL (stack becomes logically empty)
    Edge cases: S == NULL (would crash because the function dereferences S; caller must pass a valid pointer)

Algorithm

    Set S->top to NULL

Function: push

Problem Understanding

    Input: S — pointer to a Stack, value — integer to push onto the stack
    Output: allocates a new node and pushes it onto the top of the stack; returns 1 on success, 0 on allocation failure
    Edge cases:
        S == NULL (would crash because the function dereferences S; caller must pass a valid pointer)
        memory allocation failure (malloc returns NULL) → returns 0

Algorithm

    Allocate a new Node
        If allocation fails, return 0
    Set newNode->data = value
    Set newNode->next = S->top
    Set S->top = newNode
    Return 1

Function: pop

Problem Understanding

    Input: S — pointer to a Stack
    Output: removes the top element from the stack and returns its value; if stack is empty returns SENTINEL
    Edge cases:
        S == NULL (would crash because the function dereferences S; caller must pass a valid pointer)
        S->top == NULL (stack empty) → returns SENTINEL
        SENTINEL could be a valid stack value (API limitation)

Algorithm

    If S->top == NULL, return SENTINEL
    Store S->top in a temporary pointer (temp)
    Save temp->data into value
    Update S->top = S->top->next
    Free temp
    Return value

Function: peek

Problem Understanding

    Input: S — pointer to a Stack
    Output: returns the value at the top of the stack without removing it; if stack is empty returns SENTINEL
    Edge cases:
        S == NULL (would crash because the function dereferences S; caller must pass a valid pointer)
        stack empty (S->top == NULL) → returns SENTINEL
        SENTINEL could be a valid stack value (API limitation)

Algorithm

    If S->top == NULL, return SENTINEL
    Return S->top->data

Function: display

Problem Understanding

    Input: S — pointer to a constant Stack (stack content will not be modified)
    Output: prints stack contents from top to bottom in the form x -> y -> ... -> NULL
    Edge cases:
        S == NULL → function returns immediately (prints nothing)
        S->top == NULL → prints NULL

Algorithm

    If S == NULL, return
    Set cur = S->top
    While cur != NULL
        Print cur->data followed by " -> "
        Move cur = cur->next
    Print "NULL\n"

Function: freeStack

Problem Understanding

    Input: S — pointer to a Stack (output parameter: nodes will be freed and top reset)
    Output: frees all nodes in the stack and sets S->top = NULL (stack becomes empty)
    Edge cases:
        S == NULL → function returns immediately
        stack already empty (S->top == NULL) → loop does nothing

Algorithm

    If S == NULL, return
    Set cur = S->top
    While cur != NULL
        Save next pointer: nxt = cur->next
        Free cur
        Move cur = nxt
    Set S->top = NULL

Block pasted, 1 total
