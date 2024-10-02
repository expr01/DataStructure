#include "SingleLinkedList.h"

// 노드 생성
Node* SLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData; // 데이터 저장
	NewNode->NextNode = NULL; // 다음 노드에 대한 포인터 NULL로 초기화

	return NewNode; // 노드의 주소 반환
}

// 노드 소멸
void SLL_DestroyNode(Node* Node) {
	free(Node);
}

// 노드 추가
void SLL_AppendNode(Node** Head, Node* NewNode) {
	// Head 노드가 Null이면 새로운 Head가 된다.
	if (*Head == NULL) {
		*Head = NewNode;
	}
	else {
		// Tail을 찾아서 NewNode를 연결
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

// 특정 노드 뒤에 새로운 노드 추가
void SLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

// 새로운 헤드 추가
void SLL_InsertNewHead(Node** Head, Node* NewHead) {
	if (Head == NULL) {
		(*Head) = NewHead;
	}
	else {
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

// 노드 삭제 연산
void SLL_RemoveNode(Node** Head, Node* Remove) {
	if (*Head == Remove) {
		*Head = Remove->NextNode;
	}
	else {
		Node* Current = *Head;
		while (Current != NULL && Current->NextNode != Remove) {
			Current = Current->NextNode;
		}

		if (Current != NULL) {
			Current->NextNode = Remove->NextNode;
		}
	}
}

// 노드 탐색 연산
Node* SLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}

	return Current;
}

// 노드의 개수
int SLL_GetNodeCount(Node* Head) {
	int Count = 0;
	Node* Current = Head;

	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}

	return Count;
}