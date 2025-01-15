#include "linkedlist.h"

void initList(Node **pList) {
    *pList = NULL;
}
Node *createNode(Movie newData) {
    // goal is to allocate space on heap and init with Movie data

    Node *pMem = malloc(sizeof(Node));

    // is the space allocated on the heap?
    if (pMem != NULL) {
        // space allocated successfully
        pMem->pNext = NULL;
        pMem->data = newData;  // struct assignment
    }

    return pMem;
}
int insertAtFront(Node *headNode, Movie newData);