#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode
{
    ElementType data;
    struct tagNode* prevNode;
    struct tagNode* nextNode;
} Node;

Node* DLL_CreateNode(ElementType newData);
void DLL_DestroyNode(Node* node);
void DLL_AppendNode(Node** head, Node* newNode);
void DLL_InsertBefore(Node* Current, Node* newNode);
void DLL_InsertAfter(Node* Current, Node* newNode);
void DLL_RemoveNode(Node** Head, Node* Remove);
Node* DLL_GetNodeAt(Node* Head, int Location);
int DLL_GetNodeCount(Node* Head);
void PrintNode(Node* node);
void PrintList(Node* list);

#endif