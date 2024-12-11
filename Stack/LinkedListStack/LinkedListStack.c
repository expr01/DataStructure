#include "LinkedList.h"

void LLS_CreateStack(LinkedListStack** stack){
    (*stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
    (*stack)->list = NULL;
    (*stack)->top = NULL;
}

void LLS_DestroyStack(LinkedListStack* stack){
    while (!LLS_IsEmpty(stack)) {
        Node* popped = LLS_Pop(stack);
        LLS_DestroyNode(popped);
    }

    free(stack);
}

Node* LLS_CreateNode(char* newData){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(strlen(newData) + 1);

    strcpy(newNode->data, newData);

    newNode->nextNode = NULL;

    return newNode;
}

void LLS_DestroyNode(Node* node){
    free(node->data);
    free(node);
}


void LLS_Push(LinkedListStack* stack, Node* newNode){
    if (stack->list == NULL) {
        stack->list = newNode;
    }
    else {
        stack->top->nextNode = newNode;
    }

    stack->top = newNode;
}

Node* LLS_Pop(LinkedListStack* stack){
    // 반환할 최상위 노드 저장
    Node* topNode = stack->top;

    // stack이 비었다면 NULL로 설정
    if (stack->list == stack->top) {
        stack->list = NULL;
        stack->top = NULL;
    }
    else {
        // top 아래에 있던 노드를 새로운 top으로 설정
        Node* currentTop = stack->list;
        while (currentTop != NULL && currentTop->nextNode != stack->top) {
            currentTop = currentTop->nextNode;
        }

        stack->top = currentTop;
        stack->top->nextNode = NULL;
    }
    
    return topNode;
}

Node* LLS_Top(LinkedListStack* stack){
    return stack->top;
}

int LLS_GetSize(LinkedListStack* stack){
    int count = 0;
    Node* current = stack->list;

    while (current != NULL) {
        current = current->nextNode;
        count++;
    }

    return count;
}

int LLS_IsEmpty(LinkedListStack* stack){
    return (stack->list == NULL);
}
