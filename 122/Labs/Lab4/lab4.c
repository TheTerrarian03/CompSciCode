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
    return rand() % (max_inc+1);
}
int getRandRangeExcl(int max_excl) {
    return rand() % max_excl;
}

#pragma endregion

#pragma region Stack Operations

int isEmpty(Node* pTop) {
    return !pTop;
}

int push(Node** pTop, Point newPoint) {
    int alloc_success = 0;

    Node *pMem = (Node *)malloc(sizeof(Node));
    if (pMem) {
        pMem->currentPoint = newPoint;
        pMem->pNext = *pTop;
        *pTop = pMem;
        alloc_success = 1;
    }

    return alloc_success;
}

Point pop(Node** pTop) {
    // if list is empty, return 0
    if (isEmpty(*pTop)) return nullPoint();

    // else get value and pop top Node
    Point top_val = (*pTop)->currentPoint;
    Node *next = (*pTop)->pNext;
    free(*pTop);
    *pTop = next;

    return top_val;
}

Point peek(Node* pTop) {
    return pTop != NULL ? pTop->currentPoint : nullPoint();
}

#pragma endregion

#pragma region Point and Coord Operations

Point nullPoint() {
    Point newPoint = {.coord = {.x = -1, .y = -1}, .forks = {}};
    return newPoint;
}

int pointAtCoord(Node *stack, Coord tgt) {
    while (stack != NULL) {
        // printf("Checking (%d, %d) against (%d, %d)\n", stack->currentPoint.coord.x, stack->currentPoint.coord.y, tgt.x, tgt.y);
        if (stack->currentPoint.coord.x == tgt.x && stack->currentPoint.coord.y == tgt.y) {
            return 1;
        }
        stack = stack->pNext;
    }

    return 0;
}
int coordsMatch(Coord c1, Coord c2) {
    return (c1.x == c2.x) && (c1.y == c2.y);
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
    Point start = nullPoint();

    while (iters < 100) {
        int x = getRandRangeExcl(MAZE_WIDTH);
        if (maze_arr[0][x] == 1) {
            start.coord.x = x;
            start.coord.y = 0;
            break;
        }
        iters++;
    }

    return start;
}
Point randValidEnd(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH]) {
    int iters = 0;
    Point end = nullPoint();

    while (iters < 100) {
        int x = getRandRangeExcl(MAZE_WIDTH);
        if (maze_arr[MAZE_HEIGHT-1][x] == 1) {
            end.coord.x = x;
            end.coord.y = MAZE_HEIGHT-1;
            break;
        }
        iters++;
    }

    return end;
}

void printMaze(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH], Point start, Point end, Node *stack) {
    for (int i=0; i < start.coord.x * 2; i++) putchar(' ');
    printf("_\n");
    
    for (int i=0; i < MAZE_HEIGHT; i++) {
        for (int j=0; j < MAZE_WIDTH; j++) {
            Coord curCoord = {j, i};
            if (pointAtCoord(stack, curCoord)) {
                printf("X ", maze_arr[i][j]);
            } else {
                printf("%d ", maze_arr[i][j]);
            }
        }
        putchar('\n');
    }

    for (int i=0; i < end.coord.x * 2; i++) putchar(' ');
    printf("^\n");
}

int mazeSolveLoop(int maze_arr[MAZE_HEIGHT][MAZE_WIDTH], Point start, Point end, Node **stack) {
    /*
    while (not at end)

        find forks and possible coords to go to for current point at top of stack

        if there are no forks
            backtrack (pop) and remove past coord from forks in new top point

        choose a path to go
        // 
    */

    while (!coordsMatch(peek(*stack).coord, end.coord)) {
        printf("Running maze!\n");

        
    }
}

#pragma endregion