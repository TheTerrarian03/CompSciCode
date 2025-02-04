/*
 * File: lab4.c
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Spring 2025
 * Assignment: Lab 4
 */

#include "lab4.h"

#pragma region Random Funcs

void seedRand() {
    srand((unsigned int)time(NULL));
}
int getRandBool() {
    return !(!(rand() % 3));
}
int getRandRangeInc(int max_inc) {
    return rand() % max_inc+1;
}
int getRandRangeExcl(int max_inc) {
    return rand() % max_inc+1;
}

#pragma endregion

#pragma region Stack Operations

int isEmpty(Node* pTop) {
    return !pTop;
}

int push(Node** pTop, double data) {
    int alloc_success = 0;

    Node *pMem = (Node *)malloc(sizeof(Node));
    if (pMem) {
        pMem->data = data;
        pMem->pNext = *pTop;
        *pTop = pMem;
        alloc_success = 1;
    }

    return alloc_success;
}

double pop(Node** pTop) {
    // if list is empty, return 0
    if (isEmpty(*pTop)) return 0.0;

    // else get value and pop top Node
    double top_val = (*pTop)->data;
    Node *next = (*pTop)->pNext;
    free(*pTop);
    *pTop = next;

    return top_val;
}

double peek(Node* pTop) {
    return pTop != NULL ? pTop->data : 0.0;
}

#pragma endregion

#pragma region Maze Operations

void initMaze(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]) {
    for (int i=0; i < MAZE_HEIGHT; i++) {
        for (int j=0; j < MAZE_WIDTH; j++) {
            maze_arr[i][j] = 1;
        }
    }
}

void genMaze(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]) {
    for (int i=0; i < MAZE_HEIGHT; i++) {
        for (int j=0; j < MAZE_WIDTH; j++) {
            maze_arr[i][j] = getRandBool();
        }
    }
}

Point randValidStart(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]) {
    int iters = 0;

    while (iters < 100) {
        int x = getRandInRange(MAZE_WIDTH);
    }    
}
Point randValidEnd(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]);

void printMaze(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]) {
    for (int i=0; i < MAZE_HEIGHT; i++) {
        for (int j=0; j < MAZE_WIDTH; j++) {
            printf("%d ", maze_arr[i][j]);
        }
        putchar('\n');
    }
}

#pragma endregion