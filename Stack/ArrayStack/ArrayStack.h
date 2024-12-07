#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {
    ElementType data;
} Node;

typedef struct tagArrayStack {
    int capacity;
    int top;
    Node* nodes;
} ArrayStack;

void AS_CreateStack(ArrayStack** stack, int capacity);
void AS_DestroyStack(ArrayStack* stack);
void AS_Push(ArrayStack* stack, ElementType data);
ElementType AS_Pop(ArrayStack* stack);
ElementType AS_Top(ArrayStack* stack);
int AS_GetSize(ArrayStack* stack);
int AS_IsEmpty(ArrayStack* stack);
int AS_IsFull(ArrayStack* stack);

#endif