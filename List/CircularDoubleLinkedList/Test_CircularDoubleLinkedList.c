#include "CircularDoubleLinkedList.h"

int main() {

    int i = 0;
    int count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;

    for (i = 0; i < 5; i++)
    {
        NewNode = CDLL_CreateNode(i);
        CDLL_AppendNode(&List, NewNode);
    }

    // 리스트 출력
    PrintList(List);

    // 리스트 세 번째 노드 뒤 새 노드 삽입
    printf("\nInserting 3000 After [2]..\n\n");

    Current = CDLL_GetNodeAt(List, 2);
    NewNode = CDLL_CreateNode(3000);
    CDLL_InsertAfter(Current, NewNode);

    PrintList(List);

    Current = CDLL_GetNodeAt(List, 5);
    NewNode = CDLL_CreateNode(4000);
    CDLL_InsertBefore(Current, NewNode);
    
    printf("\nInserting 4000 Before [5]..\n\n");

    // 리스트 출력
    PrintList(List);

    // 모든 노드를 메모리에서 제거
    printf("\nDestorying List...\n");

    count = CDLL_GetNodeCount(List);

    for (i = 0; i < count; i++) {
        Current = CDLL_GetNodeAt(List, 0);

        if (Current != NULL) {
            CDLL_RemoveNode(&List, Current);
            CDLL_DestroyNode(Current);
        }
    }

    return 0;
}