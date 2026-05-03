#include<iostream>
#include"Common.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>

using std::cout;


struct List {
    Node* head;
    int size;
};


struct DLL {
    dNode* head;
    dNode* tail;
    int size;
};


void initList(Node*& head) {
    head = nullptr;                 
}

void printList(Node* head) {
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        std::cout << cur->data << '\n';
    }
}

void appendList(Node*& head, int value) {
    Node* newNode = new Node{ value, nullptr };

    if (head == nullptr) {   // empty list
        head = newNode;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = newNode;
}

void addAtBeginning(Node*& head, int value) {
    Node* newNode = new Node{ value, head };
    head = newNode;
}

void insertAt(Node*& head, int at, int value) {
    if (at == 0) {
        addAtBeginning(head, value);
        return;
    }
    Node* cur = head;
    for (int i = 0; i < at - 1; i++) {
        if (cur == nullptr) {
            std::cout << "Index out of range.";
            return;
        }
        cur = cur->next;
    }
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = cur->next;
    cur->next = newNode;
}

int deleteBeginning(Node*& head) {
    if (head == nullptr) {
        std::cout << "List is empty.";
        return -1; // or throw an exception
    }
    int value = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    return value;
}

int deleteEnd(Node*& head) {
    if (head == nullptr) {
        std::cout << "List is empty.";
        return -1; // or throw an exception
    }
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        if (cur->next == nullptr) { // last node
            int value = cur->data;
            delete cur;             
            return value;
        }
    }
    return -1; 
}


int deleteBeginning(List* L) {
    if (L == nullptr || L->head == nullptr)
        return -1;

    Node* old = L->head;
    int val = old->data;
    L->head = old->next;
    free(old);          
    L->size--;
    return val;
}

int deleteEnd(List* L) {
    if (L == nullptr || L->head == nullptr)
        return -1;

    if (L->head->next == nullptr) {
        int val = L->head->data;
        free(L->head);
        L->head = nullptr;
        L->size--;
        return val;
    }

    Node* prev = nullptr;
    Node* cur = L->head;

    while (cur->next != nullptr) {
        prev = cur;
        cur = cur->next;
    }

    int val = cur->data;
    prev->next = nullptr;
    free(cur);
    L->size--;
    return val;
}

int deleteByValue(List* L, int value) {
    if (L == nullptr || L->head == nullptr)
        return -1;

    if (L->head->data == value)
        return deleteBeginning(L);

    Node* prev = L->head;
    Node* cur = L->head->next;

    while (cur != nullptr) {
        if (cur->data == value) {
            prev->next = cur->next;    /* bypass target node      */
            free(cur);
            L->size--;
            return value;
        }
        prev = cur;
        cur = cur->next;
    }

    return -1;
}

Node* searchValue(List* L, int value) {
    if (L == nullptr) return nullptr;

    Node* cur = L->head;
    while (cur != nullptr) {
        if (cur->data == value)
            return cur;
        cur = cur->next;
    }
    return nullptr;
}

void displayList(List* L) {
    if (L == nullptr) return;

    Node* cur = L->head;
    while (cur != nullptr) {
        printf("%d ->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

void reverseList(List* L) {
    if (L == nullptr) return;

    Node* prev = nullptr;
    Node* cur = L->head;
    Node* nxt = nullptr;

    while (cur != nullptr) {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    L->head = prev;
}


void sortListBubble(List* L) {
    if (L == nullptr || L->head == nullptr) return;

    int swapped;
    Node* cur;
    Node* last = nullptr;

    do {
        swapped = 0;
        cur = L->head;

        while (cur->next != last) {
            if (cur->data > cur->next->data) {
                int tmp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = tmp;
                swapped = 1;
            }
            cur = cur->next;
        }
        last = cur;
    } while (swapped);
}


void initList(List* L) {
    L->head = nullptr;
    L->size = 0;
}

int insertEnd(List* L, int value) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) return -1;
    n->data = value;
    n->next = nullptr;

    if (L->head == nullptr) {
        L->head = n;
        L->size++;
        return value;
    }

    Node* cur = L->head;
    while (cur->next != nullptr) cur = cur->next;
    cur->next = n;
    L->size++;
    return value;
}

void mergeSortedLists(List* A, List* B, List* result) {
    initList(result);
    Node* pA = (A ? A->head : nullptr);
    Node* pB = (B ? B->head : nullptr);

    while (pA != nullptr && pB != nullptr) {
        if (pA->data <= pB->data) {
            insertEnd(result, pA->data);
            pA = pA->next;
        }
        else {
            insertEnd(result, pB->data);
            pB = pB->next;
        }
    }
    while (pA != nullptr) { insertEnd(result, pA->data); pA = pA->next; }
    while (pB != nullptr) { insertEnd(result, pB->data); pB = pB->next; }
}



void initListDLL(DLL* L) {
    L->head = nullptr;
    L->tail = nullptr;
    L->size = 0;
}

/* ── insertBeginningDLL ─────────────────────────────────────── */
int insertBeginningDLL(DLL* L, int value) {
    dNode* newNode = (dNode*)malloc(sizeof(dNode));
    if (!newNode) return -1;           /* allocation failed */

    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = L->head;

    if (L->head != nullptr)
        L->head->prev = newNode;       /* old head gets back-link */
    else
        L->tail = newNode;             /* list was empty          */

    L->head = newNode;
    L->size++;
    return value;
}

/* ── insertEndDLL ───────────────────────────────────────────── */
int insertEndDLL(DLL* L, int value) {
    dNode* newNode = (dNode*)malloc(sizeof(dNode));
    if (!newNode) return -1;

    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = L->tail;

    if (L->tail != nullptr)
        L->tail->next = newNode;       /* old tail gets forward-link */
    else
        L->head = newNode;             /* list was empty             */

    L->tail = newNode;
    L->size++;
    return value;
}

/* ── deleteByValueDLL ───────────────────────────────────────── */
int deleteByValueDLL(DLL* L, int value) {
    dNode* cur = L->head;

    while (cur != nullptr) {
        if (cur->data == value) {

            /* Re-link previous neighbor */
            if (cur->prev != nullptr)
                cur->prev->next = cur->next;
            else
                L->head = cur->next;   /* deleted node was head   */

            /* Re-link next neighbor */
            if (cur->next != nullptr)
                cur->next->prev = cur->prev;
            else
                L->tail = cur->prev;   /* deleted node was tail   */

            free(cur);
            L->size--;
            return value;
        }
        cur = cur->next;
    }

    return -1;                         /* value not found         */
}

/* ── displayForward ─────────────────────────────────────────── */
void displayForward(DLL* L) {
    dNode* cur = L->head;

    printf("HEAD <-> ");
    while (cur != nullptr) {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

/* ── displayBackward ────────────────────────────────────────── */
void displayBackward(DLL* L) {
    dNode* cur = L->tail;

    printf("TAIL <-> ");
    while (cur != nullptr) {
        printf("%d <-> ", cur->data);
        cur = cur->prev;
    }
    printf("NULL\n");
}
