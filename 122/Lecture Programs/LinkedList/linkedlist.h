#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct movie
{
    char title[25];
    int year;
}Movie;

typedef struct node
{
    Movie data;
    struct node* pNext;
} Node;

void initList(Node** pList); // set the list to empty
Node* createNode(Movie newData); // helper for insert
int insertFront(Node** pList, Movie newData); // insertFront (L, e) ADT
int insertInOrder(Node **pList, Movie newData);
Movie delteFront(Node **pList);
void destroyList(Node **pList);

void printList(Node* pHeadCpy);

#endif