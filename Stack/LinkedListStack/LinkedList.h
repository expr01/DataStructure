#ifndef LINKEDLIST_STACK_H
#define  LINKEDLIST_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
    char* data;
    struct tagNode* nextNode;
} Node;

typedef struct tagLinkedListStack {
    Node* list;
    Node* top;
} LinkedListStack;

void LLS_CreateStack(LinkedListStack** stack);
void LLS_DestroyStack(LinkedListStack* stack);

Node* LLS_CreateNode(char* data);
void LLS_DestroyNode(Node* node);

void LLS_Push(LinkedListStack* stack, Node* newNode);
Node* LLS_Pop(LinkedListStack* stack);

Node* LLS_Top(LinkedListStack* stack);
int LLS_GetSize(LinkedListStack* stack);
int LLS_IsEmpty(LinkedListStack* stack);

#endif