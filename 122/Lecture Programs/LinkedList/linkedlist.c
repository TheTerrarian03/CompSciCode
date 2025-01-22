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
int insertAtFront(Node** pList, Movie newData) {
    // case 1) empty
    // case 2) containes title and year
        // case 2.1) 
    
    Node *pMem = createNode(newData);
    int success = 0;

    if (pMem != NULL) {
        // allocated space for a node
        success = 1;

        // is the list empty?
        if (*pList == NULL) {
            // yes, empty, set pList to the new node we created
            *pList = pMem;
        } else {
            // no, list is not empty
            pMem->pNext = *pList;
            *pList = pMem;
        }
    }

    return success;
}

Movie deleteFront(Node **pList) {
    Node *pTemp = *pList;
    Movie deleted = (*pList)->data;  // struct assignment

    *pList = pTemp->pNext;
    free(pTemp);

    return deleted;  // return copy of a struct
}

int insertInOrder(Node **pList, Movie newData) {
    
}

void printList(Node* pHeadCpy) {
    // base case
    if (pHeadCpy == NULL) {
        printf("-->\n");
    }
    // recursive step
    else {
        printf("--> %s, %d ", pHeadCpy->data.title, pHeadCpy->data.year);
        printList(pHeadCpy->pNext);
    }
}