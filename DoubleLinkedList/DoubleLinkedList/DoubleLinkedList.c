#include "DoubleLinkedList.h"

// 노드 생성
Node* DLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

// 노드 소멸
void DLL_DestroyNode(Node* Node) {
	free(Node);
}

// 리스트에 노드 추가
void DLL_AppendNode(Node** Head, Node* NewNode) {
	// 헤드 노드가 NULL이라면 새 노드가 Head가 됨
	if ((*Head) == NULL) {
		(*Head) = NewNode;
	}
	else {
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}

		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

// 노드 삽입
void DLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
		Current->NextNode = NewNode;
	}
}

// 노드 제거
void DLL_RemoveNode(Node** Head, Node* Remove) {
	// Head가 제거할 노드 위치에 있을 때
	if (*Head == Remove) {
		*Head = Remove->NextNode;
		if ((*Head) != NULL) {
			(*Head)->PrevNode = NULL;
		}
	}
	else {
		Node* Temp = Remove;
		// Remove가 첫번 째 노드가 아닐 때
		if (Remove->PrevNode != NULL) {
			Remove->PrevNode->NextNode = Temp->NextNode;
		}
		// Remove가 마지막 노드가 아닐 때
		if (Remove->NextNode != NULL) {
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}
	}

	Remove->PrevNode = NULL;
	Remove->NextNode = NULL;
}

// 노드 탐색
Node* DLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}

	return Current;
}

// 노드 개수
int DLL_GetNodeCount(Node* Head) {
	unsigned int Count = 0;
	Node* Current = Head;
	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}

// 노드 출력
void PrintNode(Node* _Node) {
	if (_Node->PrevNode == NULL) {
		printf("Prev: NULL");
	}
	else {
		printf("Prev : %d", _Node->PrevNode->Data);
		printf("Current : %d", _Node->Data);
	}
	
	if (_Node->NextNode == NULL) {
		printf("Next: NULL\n");
	}
	else {
		printf("Next : %d", _Node->NextNode->Data);
	}
}