#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* pNext;
    struct node* pPrev;
} Node;

void printList(Node *pList);
void printBack(Node *pTail);
Node *getTail(Node *pList);
Node *makeNode(int data);
Node *insertAtFront(Node **pList, int data);
Node *mergeList(Node **pList1, Node **pList2);

int main() {
    Node *pList1 = makeNode(6);

    pList1 = insertAtFront(&pList1, 5);
    pList1 = insertAtFront(&pList1, 4);
    pList1 = insertAtFront(&pList1, 3);
    pList1 = insertAtFront(&pList1, 2);
    pList1 = insertAtFront(&pList1, 1);

    Node *pList2 = makeNode(10);

    pList2 = insertAtFront(&pList2, 9);
    pList2 = insertAtFront(&pList2, 8);
    pList2 = insertAtFront(&pList2, 7);

    printList(pList1);
    printList(pList2);
    
    mergeList(&pList1, &pList2);
    printList(pList1);
    printBack(getTail(pList1));

}

void printList(Node *pList) {
    if (pList == NULL) {
        printf("List empty\n");
        return;
    }

    printf("%d\n", pList->data);
    printList(pList->pNext);
}
void printBack(Node *pTail) {
    if (pTail == NULL) {
        printf("List empty\n");
        return;
    }

    printf("%d\n", pTail->data);
    printBack(pTail->pPrev);
}

Node *getTail(Node *pList) {
    if (pList == NULL) {
        printf("empty list\n");
        return NULL;
    }

    Node *pCur = pList;

    while (pCur->pNext != NULL) {
        pCur = pCur->pNext;
    }

    return pCur;
}

Node *makeNode(int data) {
    Node *pNew = (Node *)malloc(sizeof(Node));

    if (!pNew) return NULL;

    pNew->data = data;
    pNew->pNext = NULL;
    pNew->pPrev = NULL;

    return pNew;
}

Node *insertAtFront(Node **pList, int data) {
    Node *pMem = makeNode(data);

    pMem->pNext = *pList;

    if (pMem->pNext) (*pList)->pPrev = pMem;

    // *pList = pMem;

    return pMem;
}

Node *mergeList(Node **pList1, Node **pList2) {
    if (*pList1 == NULL) {
        return *pList2;
    }

    Node *pCur = *pList1;
    // Node *pPrev = NULL;

    while (pCur->pNext != NULL) {
        // pPrev = pCur;
        pCur = pCur->pNext;
    }

    // pPrev->pNext = *pList2;
    pCur->pNext = *pList2;
    (*pList2)->pPrev = pCur;
    return *pList1;
}
// Node* mergeList(Node** pList1, Node** pList2){
//     Node *pCur = *pList1;
//     Node *pPrev = NULL;
//     while(pCur != NULL){
//         pPrev = pCur;
//         pCur = pCur->pNext;
//     }
//     if(pPrev != NULL){
//         pPrev->pNext = *pList2;
//         return *pList1;
//     }
//     else{
//         return *pList2;
//     }
// }   