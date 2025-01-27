#include "linkedlist.h"

void initList(Node** pList) // set the list to empty
{
    *pList = NULL; // assigning the list as an empty list
}

Node* createNode(Movie newData)
{
    // goal is to allocate space on heap and init with Movie data

    Node* pMem = malloc(sizeof(Node));

    // is the space allocated on the heap?
    if (pMem != NULL)
    {
        // yes, we allocated space successfully

        // let's init the space - Node
        pMem->pNext = NULL;
        pMem->data = newData; // struct assignment
    }

    return pMem; // it's possible that pMem contains NULL
}

int insertFront(Node** pList, Movie newData)
{
    Node* pMem = createNode(newData);
    int success = 0;

    if (pMem != NULL)
    {
        // yes, we allocated space for a Node
        success = 1;

        // is the list empty?
        if (*pList == NULL)
        {
            // yes, it's empty
            *pList = pMem; // modifying the direct value of pHead
        }
        else
        {
            // no, list is not empty
            pMem->pNext = *pList;
            (*pList)->pPrev = pMem;
            *pList = pMem;
        }
    }

    return success;
}

int insertInOrder(Node **pList, Movie newData) {
    Node *pMem = createNode(newData), *pCur = *pList, *pPrev = NULL;
    int success = 0;

    if (pMem != NULL) {
        // pCur check before strcmp is important for avoiding crash
        while (pCur != NULL && strcmp(pCur->data.title, newData.title) < 0) {
            // advance
            pPrev = pCur;
            pCur = pCur->pNext;
        }

        // we have found the spot to insert in order
        // inserting at front?
        if (pPrev == NULL) {
            // front
            pMem->pNext = *pList;
            *pList = pMem;
        } else {
            // not empty or not  at front
            pMem->pNext = pCur;
            pPrev->pNext = pMem;
        }
    }

    return success;
}

void destroyList(Node **pList) {
    // recursive step case
    if (*pList != NULL)
    {
        destroyList(&((*pList)->pNext));
        printf("Desroying: %s\n", (*pList)->data.title);
        free(*pList);
        *pList = NULL;
        // free()
    }
}

void printList(Node* pHeadCpy)
{
    // base case
    if (pHeadCpy == NULL)
    {
        printf("-->\n"); // either we're at the end of the list
    }
    else // recursive step
    {
        // we know the current pointer is referring to a Node;
        // let's print the data
        printf("--> %s, %d ", pHeadCpy->data.title, 
            pHeadCpy->data.year);
        printList(pHeadCpy->pNext); // move to the next Node in the list
    }
}
