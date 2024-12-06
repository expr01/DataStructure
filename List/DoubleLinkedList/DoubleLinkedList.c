#include "DoubleLinkedList.h"

// 노드 생성
Node* DLL_CreateNode(ElementType newData) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = newData;
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;

    return newNode;
}

// 노드 삭제
void DLL_DestroyNode(Node* node) {
    free(node);
}

// 노드 추가
void DLL_AppendNode(Node** head, Node* newNode) {
    // 헤드 노드가 NULL이라면 새로운 노드가 헤드
    if ((*head) == NULL) *head = newNode;
    else {
        // 리스트의 마지막까지 가서 추가
        Node* tail = (*head);
        while (tail->nextNode != NULL) {
            tail = tail->nextNode;
        }
        tail->nextNode = newNode;
        newNode->prevNode = tail;
    }
}

// 노드 전 삽입
void DLL_InsertBefore(Node* current, Node* newNode) {
    newNode->nextNode = current;
    newNode->prevNode = current->prevNode;

    if (current->prevNode != NULL) {
        current->prevNode->nextNode = newNode;
        current->prevNode = newNode;
    }
}

// 노드 뒤 삽입
void DLL_InsertAfter(Node* current, Node* newNode) {
    newNode->nextNode = current->nextNode;
    newNode->prevNode = current;

    // 삽입 위치 뒤 노드가 더 있는지 확인해서 삽입
    if (current->nextNode != NULL) {
        current->nextNode->prevNode = newNode;
        current->nextNode = newNode;
    }
}

// 노드 제거 (Node* remove: 제거할 노드)
void DLL_RemoveNode(Node** head, Node* remove) {

    // 제거할 노드가 헤드인 경우
    if ((*head) == remove) {
        *head = remove->nextNode; // 헤드를 다음 노드로 바꿈
        if ((*head) != NULL) (*head)->prevNode = NULL; // 새로운 헤드의 이전 노드가 없도록 설정

        // 제거할 노드의 이전/다음 링크 초기화
        remove->prevNode = NULL;
        remove->nextNode = NULL;
    }
    // 일반 노드를 제거하는 경우
    else {
        
        if (remove->prevNode != NULL) {
            remove->prevNode->nextNode = remove->nextNode;
        }

        if (remove->nextNode != NULL) {
            remove->nextNode->prevNode = remove->prevNode;
        }

        remove->prevNode = NULL;
        remove->nextNode = NULL;
    }
}

// 노드 탐색
Node* DLL_GetNodeAt(Node* head, int location) {
    Node* current = head;
    while (current != NULL && (--location) >= 0) {
        current = current->nextNode;
    }
    return current;
}

// 노드 개수 세기
int DLL_GetNodeCount(Node* head) {
    unsigned int count = 0;
    Node* current = head;
    
    while (current != NULL) {
        current = current->nextNode;
        count++;
    }

    return count;
}

void PrintNode(Node* node) {
    if (node->prevNode == NULL) {
        printf("Prev: NULL ");
    }
    else {
        printf("Prev: %d ", node->prevNode->data);
    }

    printf("Current: %d ", node->data);

    if (node->nextNode == NULL) {
        printf("Next: NULL\n");
    }

    else {
        printf("Next: %d\n", node->nextNode->data);
    }
}

void PrintList(Node* list) {
    int count = DLL_GetNodeCount(list);
    
    for (int i = 0; i < count; i++) {
        Node* current = DLL_GetNodeAt(list, i);
        printf("List[%d] : %d\n", i, current->data);
    }
}