#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType data;
    struct tagNode* nextNode;
} Node;

Node* SLL_CreateNode(ElementType newData);
void SLL_DestroyNode(Node* node);
void SLL_AppendNode(Node** head, Node* newNode);
void SLL_InsertAfter(Node* Current, Node* newNode);
void SLL_InsertNewHead(Node** head, Node* newHead);
void SLL_RemoveNode(Node** Head, Node* Remove);
Node* SLL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);

#endif