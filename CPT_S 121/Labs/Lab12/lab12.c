#include "lab12.h"

// Task 1
void reverse_string(char *string, int string_len, int index) {
    // stop if base condition met
    if (index >= string_len/2) return;

    // reverse at index and last - index
    char tmp = string[index];
    int last = (string_len-1)-index;
    printf("Index %d, Last %d, Reversing %c and %c\n", index, last, tmp, string[last]);
    string[index] = string[last];
    string[last] = tmp;

    // call function again with index+1
    reverse_string(string, string_len, index + 1);
}

// Task 2
int sum_digits(int number) {
    if (number <= 1) return number % 10;
    else return number % 10 + sum_digits(number / 10);
}

// Task 3
void walk_maze(char maze[MAZE_ROWS][MAZE_COLS], PATH_COORD moves[MAX_MOVES], int *step_count, MoveDecider moveDecider) {
    // determine win condition, at (7,7)
    if (moves[*step_count].x == 7 && moves[*step_count].y == 7) {
        printf("At the target! Done.\n");
        return;
    }

    // otherwise, make a step
    int move_direction = determine_best_move_direction(moves[*step_count], moveDecider);

    printf("Move direction: %d\n", move_direction);

    // no path found, stop
    if (move_direction == -1) {
        // TODO
        printf("!!!! NO PATH FOUND, STOPPING !!!!\n");
        return;
    }
    
    // otherwise, make the move
    else {
        // populate data at next step
        int new_x = moves[*step_count].x;
        int new_y = moves[*step_count].y;
        (*step_count)++;
        get_new_coord_for_direction(&new_x, &new_y, move_direction);
        moves[*step_count].x = new_x;
        moves[*step_count].y = new_y;
        find_possible_moves(maze, moves, *step_count);
        printf("Made move in direction %d to (%d, %d), and can now move in directions: [%d, %d, %d, %d]\n", move_direction, moves[*step_count].x, moves[*step_count].y, moves[*step_count].cardinal_move_ability[0], moves[*step_count].cardinal_move_ability[1], moves[*step_count].cardinal_move_ability[2], moves[*step_count].cardinal_move_ability[3]);
    }
}
void place_initial_step(char maze[MAZE_ROWS][MAZE_COLS], PATH_COORD moves[MAX_MOVES], int start_x, int start_y) {
    moves[0].x = start_x;
    moves[0].y = start_y;
    moves[0].step_index = 0;
    find_possible_moves(maze, moves, 0);
    printf("Placed first step at (%d, %d). Can move: [%d, %d, %d, %d]\n", start_x, start_y, moves[0].cardinal_move_ability[0], moves[0].cardinal_move_ability[1], moves[0].cardinal_move_ability[2], moves[0].cardinal_move_ability[3]);
}
void find_possible_moves(char maze[MAZE_ROWS][MAZE_COLS], PATH_COORD moves[MAX_MOVES], int step) {
    int curr_x = moves[step].x;
    int curr_y = moves[step].y;
    
    // right
    if (is_valid_move(maze, moves, step, curr_x+1, curr_y)) {
        moves[step].cardinal_move_ability[0] = 1;
    } else moves[step].cardinal_move_ability[0] = 0;

    // up
    if (is_valid_move(maze, moves, step, curr_x, curr_y-1)) {
        moves[step].cardinal_move_ability[1] = 1;
    } else moves[step].cardinal_move_ability[1] = 0;

    // left
    if (is_valid_move(maze, moves, step, curr_x-1, curr_y)) {
        moves[step].cardinal_move_ability[2] = 1;
    } else moves[step].cardinal_move_ability[2] = 0;

    // down
    if (is_valid_move(maze, moves, step, curr_x, curr_y+1)) {
        moves[step].cardinal_move_ability[3] = 1;
    } else moves[step].cardinal_move_ability[3] = 0;
}
int is_valid_coord(int x, int y) {
    if (x < 0 || x > MAZE_COLS-1) return 0;
    if (y < 0 || y > MAZE_ROWS-1) return 0;
    return 1;
}
int is_move_already_at_coord(PATH_COORD moves[MAX_MOVES], int step, int x, int y) {
    for (int i=0; i<step; i++) {
        if (moves[i].x == x && moves[i].y == y) return 1;
    }

    return 0;
}
int is_wall_at_coord(char maze[MAZE_ROWS][MAZE_COLS], int x, int y) {
    if (maze[y][x] == 'X') return 1;
    return 0;
}
int is_valid_move(char maze[MAZE_ROWS][MAZE_COLS], PATH_COORD moves[MAX_MOVES], int step, int x, int y) {
    if (is_valid_coord(x, y) &&
            !is_move_already_at_coord(moves, step, x, y) &&
            !is_wall_at_coord(maze, x, y))
        return 1;
    
    return 0;
}
void get_new_coord_for_direction(int *x, int *y, int direction) {
    switch (direction) {
        // right
        case 0: {
            (*x)+=1;
            break;
        }
        // up
        case 1: {
            (*y)-=1;
            break;
        }
        // left
        case 2: {
            (*x)-=1;
            break;
        }
        //down
        case 3: {
            (*y)+=1;
            break;
        }
        default: printf("!!!!! CRITICAL ERROR !!!!!\n");
    }
}
int determine_best_move_direction(PATH_COORD current_step, MoveDecider moveDecider) {
    switch (moveDecider) {
        case CARDINAL_INDEX_ASC: {
            for (int i=0; i < 4; i++) {
                if (current_step.cardinal_move_ability[i] == 1) return i;
            }
            return -1;
        }
        case CARDINAL_INDEX_DEC: {
            break;
        }
        case RANDOM: {
            break;
        }
        case TOWARDS_TARGET: {
            break;
        }
        default: return -1;
    }
}