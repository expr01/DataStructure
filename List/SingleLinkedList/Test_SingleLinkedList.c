#include "SingleLinkedList.h"

int main() {

    int i = 0;
    int count = 0;
    Node *List = NULL;
    Node *Current = NULL;
    Node *NewNode = NULL;

    for (i = 0; i < 5; i++)
    {
        NewNode = SLL_CreateNode(i);
        SLL_AppendNode(&List, NewNode);
    }

    NewNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&List, NewNode);

    NewNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&List, NewNode);

    // 리스트 출력
    count = SLL_GetNodeCount(List);
    
    for (i = 0; i < count; i++) {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->data);
    }

    // 리스트 세 번째 노드 뒤 새 노드 삽입
    printf("\nInserting 3000 After [2]..\n\n");

    Current = SLL_GetNodeAt(List, 2);
    NewNode = SLL_CreateNode(3000);

    SLL_InsertAfter(Current, NewNode);

    // 리스트 출력
    count = SLL_GetNodeCount(List);
    
    for (i = 0; i < count; i++) {
        Current = SLL_GetNodeAt(List, i);
        printf("List[%d] : %d\n", i, Current->data);
    }

    // 모든 노드를 메모리에서 제거
    printf("\nDestorying List...\n");

    for (i = 0; i < count; i++) {
        Current = SLL_GetNodeAt(List, 0);

        if (Current != NULL) {
            SLL_RemoveNode(&List, Current);
            SLL_DestroyNode(Current);
        }
    }

    return 0;
}