#include "Stack.h"

void initStack(Stack* pStack) {
	pStack->pTop = NULL;  // empty stack
}

Node* makeNode(Data newData) {
	Node* pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL) {
		pMem->myData = newData;
		pMem->pNext = NULL;
	}

	return pMem;
}

int push(Stack* pStack, Data newData) {
	// insert at front

	int success = 0;
	Node* pMem = makeNode(newData);

	if (pMem != NULL) {
		success = 1;

		// insert the node into the top of the stack
		pMem->pNext = pStack->pTop;
		pStack->pTop = pMem;
	}

	return success;
}

void pop(Stack* pStack) {
	// deleteFront
	Node* pTemp = pStack->pTop;

	pStack->pTop = pStack->pTop->pNext;

	free(pTemp);
}

Data peek(const Stack* pStack) {
	return pStack->pTop->myData;
}
