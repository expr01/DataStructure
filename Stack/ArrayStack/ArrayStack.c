#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** stack, int capacity) {
    (*stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

    // capacity만큼 노드 생성
    (*stack)->nodes = (Node*)malloc(sizeof(Node)*capacity);

    // capacity 및 top 초기화
    (*stack)->capacity = capacity;
    (*stack)->top = -1;
}

void AS_DestroyStack(ArrayStack* stack) {
    free(stack->nodes);
    free(stack);
}

// stack에 값을 push
void AS_Push(ArrayStack* stack, ElementType data) {
    stack->top++;
    stack->nodes[stack->top].data = data;
}

// 스택에서 값을 꺼냄
ElementType AS_Pop(ArrayStack* stack) {
    int position = stack->top--;
    return stack->nodes[position].data;
}

// Top의 데이터를 반환
ElementType AS_Top(ArrayStack* stack) {
    return stack->nodes[stack->top].data;
}

int AS_GetSize(ArrayStack* stack) {
    return stack->top + 1;
}

int AS_IsEmpty(ArrayStack* stack) {
    return (stack->top == -1);
}

int AS_IsFull(ArrayStack* stack) {
    return (stack->top == stack->capacity - 1);
}