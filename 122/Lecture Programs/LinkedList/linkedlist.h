#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct movie {
    char title[25];
    int year;
} Movie;

typedef struct node {
    Movie data;
    struct node *pNext;
} Node;

void initList(Node **pList);
Node *createNode(Movie newData);
int insertAtFront(Node** pList, Movie newData);  // insertFront(L, e); L: first item, e: data to insert

void printList(Node* pHeadCpy);

#endif