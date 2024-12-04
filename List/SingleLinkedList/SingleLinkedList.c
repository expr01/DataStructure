#include "SingleLinkedList.h"

// 노드 생성
Node* SLL_CreateNode(ElementType newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = newData;
    newNode->nextNode = NULL;

    return newNode;
}

// 노드 삭제
void SLL_DestroyNode(Node* Node) {
    printf("destroying node (data: %d)\n", Node->data);
    free(Node);
}

// 노드 추가
void SLL_AppendNode(Node** head, Node* newNode) {
    // 헤드 노드가 NULL이라면 새로운 노드가 헤드
    if ((*head) == NULL) *head = newNode;
    else {
        // 리스트의 마지막까지 가서 추가
        Node* tail = (*head);
        while (tail->nextNode != NULL) {
            tail = tail->nextNode;
        }
        tail->nextNode = newNode;
    }
}

// 노드 삽입
void SLL_InsertAfter(Node* current, Node* newNode) {
    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
}

void SLL_InsertNewHead(Node** head, Node* newHead) {
    if (head == NULL) (*head) = newHead;
    else {
        newHead->nextNode = (*head);
        (*head) = newHead;
    }
}

// 노드 제거 (Node* remove: 제거할 노드)
void SLL_RemoveNode(Node** head, Node* remove) {
    // 헤드가 제거할 노드라면 헤드를 리스트에서 제거
    if ((*head) == remove) *head = remove->nextNode;
    else {
        Node* current = *head;
        // current가 제거할 노드 바로 이전 노드를 가리키도록 탐색
        while (current != NULL && current->nextNode != remove) {
            current = current->nextNode;
        }
        if (current != NULL) current->nextNode = remove->nextNode;
    }
}

// 노드 탐색
Node* SLL_GetNodeAt(Node* head, int location) {
    Node* current =head;
    while (current != NULL && (--location) >= 0) {
        current = current->nextNode;
    }
    return current;
}

// 노드 개수 세기
int SLL_GetNodeCount(Node* head) {
    int count = 0;
    Node* current = head;
    
    while (current != NULL) {
        current = current->nextNode;
        count++;
    }

    return count;
}