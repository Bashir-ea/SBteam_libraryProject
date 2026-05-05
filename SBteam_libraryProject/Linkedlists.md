
Below is documentation for each function in your code, following the same style as your initArray sample (Function / Problem Understanding with Input, Output, Edge cases). I’m documenting them as they are written (including their current assumptions).
Function: initList(Node*& head)

Problem Understanding

    Input: head — reference to the head pointer of a singly linked list
    Output: sets head = nullptr (list becomes logically empty)
    Edge cases: none; safe to call even if head already equals nullptr

Function: printList(Node* head)

Problem Understanding

    Input: head — pointer to first node (may be nullptr)
    Output: prints each node’s data (one per line) to standard output
    Edge cases: if head == nullptr, prints nothing

Function: appendList(Node*& head, int value)

Problem Understanding

    Input:
        head — reference to the head pointer (may be nullptr for empty list)
        value — integer value to append
    Output: appends a new node containing value to the end of the list; may update head if list was empty
    Edge cases:
        if head == nullptr, the new node becomes the head
        allocation failure (new) would throw std::bad_alloc unless exceptions are disabled

Function: addAtBeginning(Node*& head, int value)

Problem Understanding

    Input:
        head — reference to the head pointer (may be nullptr)
        value — integer value to insert
    Output: creates a new node and makes it the first node; updates head
    Edge cases:
        works when list is empty (head == nullptr)
        allocation failure (new) throws std::bad_alloc

Function: insertAt(Node*& head, int at, int value)

Problem Understanding

    Input:
        head — reference to the head pointer
        at — 0-based index where the new node should be inserted
        value — integer value to insert
    Output: inserts a new node at index at (shifts the rest of the list after it)
    Edge cases:
        if at == 0, calls addAtBeginning
        if traversal reaches cur == nullptr before position at-1, prints "Index out of range." and returns without insertion
        negative at is not handled explicitly (behavior depends on loop logic; caller should avoid negative indices)
        allocation failure (new) throws std::bad_alloc

Function: deleteBeginning(Node*& head)

Problem Understanding

    Input: head — reference to the head pointer
    Output: removes the first node, updates head, and returns the removed node’s data
    Edge cases:
        if head == nullptr, prints "List is empty." and returns -1
        returning -1 can be ambiguous if -1 is a valid stored value

Function: deleteEnd(Node*& head)

Problem Understanding

    Input: head — reference to the head pointer
    Output: intended to remove the last node and return its data
    Edge cases / assumptions (important):
        if head == nullptr, prints "List is empty." and returns -1
        as written, it does not track the previous node and therefore does not correctly unlink the last node (can leave dangling pointers / corrupt list)
        returning -1 can be ambiguous if -1 is a valid value

List-based API (List* L) Documentation
Function: initList(List* L)

Problem Understanding

    Input: L — pointer to a List structure (must be valid)
    Output: initializes list to empty by setting L->head = nullptr and L->size = 0
    Edge cases: if L == nullptr, dereferencing would crash; caller must pass a valid pointer

Function: insertEnd(List* L, int value)

Problem Understanding

    Input:
        L — pointer to a valid List
        value — value to append
    Output: appends a new node with value, updates L->size, returns the inserted value (or -1 on allocation failure)
    Edge cases:
        if L->head == nullptr, inserted node becomes head
        allocation failure returns -1

Function: deleteBeginning(List* L)

Problem Understanding

    Input: L — pointer to a valid List
    Output: deletes the first node, updates L->head, decrements L->size, returns deleted value
    Edge cases:
        if L == nullptr or L->head == nullptr, returns -1
        uses free() so nodes are assumed to have been allocated with malloc() in this API

Function: deleteEnd(List* L)

Problem Understanding

    Input: L — pointer to a valid List
    Output: deletes the last node, updates links, decrements L->size, returns deleted value
    Edge cases:
        if L == nullptr or L->head == nullptr, returns -1
        if only one node exists, deletes it and sets L->head = nullptr
        uses free() (assumes malloc allocation in this API)

Function: deleteByValue(List* L, int value)

Problem Understanding

    Input:
        L — pointer to a valid List
        value — value to delete (first occurrence)
    Output: deletes the first node whose data == value, decrements L->size, returns value if found/deleted
    Edge cases:
        if L == nullptr or empty list, returns -1
        if the head matches, calls deleteBeginning(L)
        if not found, returns -1

Function: searchValue(List* L, int value)

Problem Understanding

    Input:
        L — pointer to a valid List
        value — value to search for
    Output: returns pointer to the first node where data == value, or nullptr if not found
    Edge cases: if L == nullptr, returns nullptr

Function: displayList(List* L)

Problem Understanding

    Input: L — pointer to a valid List
    Output: prints the list as a -> b -> ... -> NULL using printf
    Edge cases: if L == nullptr prints nothing; if empty list prints NULL

Function: reverseList(List* L)

Problem Understanding

    Input: L — pointer to a valid List
    Output: reverses the list in-place by rewiring next pointers; updates L->head
    Edge cases:
        if L == nullptr does nothing
        if list is empty or has one node, result is unchanged

Function: sortListBubble(List* L)

Problem Understanding

    Input: L — pointer to a valid List
    Output: sorts the list in ascending order using bubble sort by swapping data fields
    Edge cases:
        if L == nullptr or list is empty, does nothing
        stable/unstable behavior depends on equality handling (it swaps only when >)

Function: mergeSortedLists(List* A, List* B, List* result)

Problem Understanding

    Input:
        A — pointer to first sorted list (ascending)
        B — pointer to second sorted list (ascending)
        result — pointer to list to store merged output
    Output: initializes result to empty then inserts elements from A and B in sorted order into result
    Edge cases:
        if A or B is empty, result becomes a copy of the other
        assumes result is a valid pointer
        assumes insertEnd(result, ...) succeeds; if allocation fails, behavior is partial merge (no rollback)

Doubly Linked List API (DLL*) Documentation
Function: initListDLL(DLL* L)

Problem Understanding

    Input: L — pointer to a valid DLL
    Output: sets L->head = nullptr, L->tail = nullptr, and L->size = 0
    Edge cases: if L == nullptr, dereferencing crashes; caller must pass valid pointer

Function: insertBeginningDLL(DLL* L, int value)

Problem Understanding

    Input:
        L — pointer to a valid DLL
        value — value to insert at front
    Output: allocates a new dNode and inserts it at the beginning; updates head/tail/size; returns inserted value or -1 on allocation failure
    Edge cases:
        if list was empty, both head and tail become the new node
        allocation failure returns -1

Function: insertEndDLL(DLL* L, int value)

Problem Understanding

    Input:
        L — pointer to a valid DLL
        value — value to insert at end
    Output: allocates a new dNode and inserts it at the end; updates head/tail/size; returns inserted value or -1 on allocation failure
    Edge cases:
        if list was empty, both head and tail become the new node
        allocation failure returns -1

Function: deleteByValueDLL(DLL* L, int value)

Problem Understanding

    Input:
        L — pointer to a valid DLL
        value — value to delete (first occurrence)
    Output: finds first node with data == value, unlinks it by updating neighbor pointers, frees it, decrements size, returns value if deleted else -1
    Edge cases:
        if value is in head, updates L->head
        if value is in tail, updates L->tail
        if not found, returns -1

Function: displayForward(DLL* L)

Problem Understanding

    Input: L — pointer to a valid DLL
    Output: prints HEAD <-> ... <-> NULL traversing from head using next
    Edge cases: if list empty, prints HEAD <-> NULL

Function: displayBackward(DLL* L)

Problem Understanding

    Input: L — pointer to a valid DLL
    Output: prints TAIL <-> ... <-> NULL traversing from tail using prev
    Edge cases: if list empty, prints TAIL <-> NULL

