#ifndef CIRCURLAR_DOUBLE_LINKED_LIST_H
#define CIRCURLAR_DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType data;
    struct tagNode* prevNode;
    struct tagNode* nextNode;
} Node;

Node* CDLL_CreateNode(ElementType newData);
void CDLL_DestroyNode(Node* node);
void CDLL_AppendNode(Node** head, Node* newNode);
void CDLL_InsertBefore(Node* Current, Node* newNode);
void CDLL_InsertAfter(Node* Current, Node* newNode);
void CDLL_RemoveNode(Node** Head, Node* Remove);
Node* CDLL_GetNodeAt(Node* Head, int Location);
int CDLL_GetNodeCount(Node* Head);
void PrintList(Node* list);

#endif