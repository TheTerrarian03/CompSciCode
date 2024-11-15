#ifndef LAB_12_H
#define LAB_12_H

#include <stdio.h>
#include <string.h>

typedef enum {
    TASK_1,
    TASK_2,
    TASK_3,
    TASK_4
} TASK_NUM;

// Task 1
void reverse_string(char *string, int string_len, int index);

// Task 2
int sum_digits(int number);

// Task 3
typedef struct {
    int x;
    int y;
    int cardinal_move_ability[4];  // [0]=right, [1]=up, [2]=right, [3]=down
    int step_index;
} PATH_COORD;

typedef enum {
    CARDINAL_INDEX_ASC,
    CARDINAL_INDEX_DEC,
    RANDOM,
    TOWARDS_TARGET
} MoveDecider;

#define MAZE_ROWS 8
#define MAZE_COLS 8
#define MAX_MOVES 50

void walk_maze(char maze[MAZE_ROWS][MAZE_COLS], PATH_COORD moves[MAX_MOVES], int *step_count, MoveDecider moveDecider);
void place_initial_step(char maze[MAZE_ROWS][MAZE_COLS], PATH_COORD moves[MAX_MOVES], int start_x, int start_y);
void find_possible_moves(char maze[MAZE_ROWS][MAZE_COLS], PATH_COORD moves[MAX_MOVES], int step);
int is_valid_coord(int x, int y);
int is_move_already_at_coord(PATH_COORD moves[MAX_MOVES], int step, int x, int y);
int is_wall_at_coord(char maze[MAZE_ROWS][MAZE_COLS], int x, int y);
int is_valid_move(char maze[MAZE_ROWS][MAZE_COLS], PATH_COORD moves[MAX_MOVES], int step, int x, int y);
void get_new_coord_for_direction(int *x, int *y, int direction);
int determine_best_move_direction(PATH_COORD current_step, MoveDecider moveDecider);

#endif