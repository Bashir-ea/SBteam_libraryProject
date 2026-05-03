#pragma once
//Author: saif haddad
//This header file deefeines the most used linkedlists fucntion

#include"Common.h"
void initList(Node* L);
int insertBeginning(Node* L, int value);
int insertEnd(Node* L, int value);
int insertAtPosition(Node* L, int pos, int value);
int deleteBeginning(Node* L);
int deleteEnd(Node* L);
int deleteByValue(Node* L, int value);
Node* searchValue(Node* L, int value);
void displayList(Node* L);
void reverseList(Node* L);
void sortListBubble(Node* L);
void mergeSortedLists(Node* A, Node* B, Node* result);

// Doubly linked list functions
void initListDLL(dNode* L);
int insertBeginningDLL(dNode* L, int value);
int insertEndDLL(dNode* L, int value);
int deleteByValueDLL(dNode* L, int value);
void displayForward(dNode* L);
void displayBackward(dNode* L);