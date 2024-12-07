#include "CircularDoubleLinkedList.h"

// 노드 생성
Node* CDLL_CreateNode(ElementType newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = newData;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;

    return newNode;
}

// 노드 삭제
void CDLL_DestroyNode(Node* node) {
    free(node);
}

// 노드 추가
void CDLL_AppendNode(Node** head, Node* newNode) {
    // 헤드 노드가 NULL이라면 새로운 노드가 헤드
    if ((*head) == NULL) {
        *head = newNode;
        (*head)->nextNode = *head;
        (*head)->prevNode = *head;

    }
    else {
        // 헤드와 테일 사이 newNode 삽입
        Node* tail = (*head)->prevNode;

        tail->nextNode->prevNode = newNode;
        tail->nextNode = newNode;

        newNode->nextNode = (*head);
        newNode->prevNode = tail; // 새로운 테일의 prevNode가 기존 테일을 가르킴
    }
}

// 노드 전 삽입
void CDLL_InsertBefore(Node* current, Node* newNode) {
    newNode->nextNode = current;
    newNode->prevNode = current->prevNode;

    if (current->prevNode != NULL) {
        current->prevNode->nextNode = newNode;
        current->prevNode = newNode;
    }
}

// 노드 뒤 삽입
void CDLL_InsertAfter(Node* current, Node* newNode) {
    newNode->nextNode = current->nextNode;
    newNode->prevNode = current;

    // 삽입 위치 뒤 노드가 더 있는지 확인해서 삽입
    if (current->nextNode != NULL) {
        current->nextNode->prevNode = newNode;
        current->nextNode = newNode;
    }
}

// 노드 제거 (Node* remove: 제거할 노드)
void CDLL_RemoveNode(Node** head, Node* remove) {

    // 제거할 노드가 헤드인 경우
    if ((*head) == remove) {
        (*head)->prevNode->nextNode = remove->nextNode;
        (*head)->nextNode->prevNode = remove->prevNode;

        *head = remove->nextNode;

        // 제거할 노드의 이전/다음 링크 초기화
        remove->prevNode = NULL;
        remove->nextNode = NULL;
    }
    // 일반 노드를 제거하는 경우
    else {
        remove->prevNode->nextNode = remove->nextNode;
        remove->nextNode->prevNode = remove->prevNode;

        remove->prevNode = NULL;
        remove->nextNode = NULL;
    }
}

// 노드 탐색
Node* CDLL_GetNodeAt(Node* head, int location) {
    Node* current = head;
    while (current != NULL && (--location) >= 0) {
        current = current->nextNode;
    }
    return current;
}

// 노드 개수 세기
int CDLL_GetNodeCount(Node* head) {
    unsigned int count = 0;
    Node* current = head;
    
    while (current != NULL) {
        current = current->nextNode;
        count++;
        if (current == head) break; // 무한루프 방지
    }

    return count;
}

void PrintList(Node* list) {
    int count = CDLL_GetNodeCount(list);
    
    for (int i = 0; i < count; i++) {
        Node* current = CDLL_GetNodeAt(list, i);
        printf("List[%d] : %d\n", i, current->data);
    }
}