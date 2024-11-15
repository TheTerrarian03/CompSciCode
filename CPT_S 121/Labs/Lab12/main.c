#include "lab12.h"

int main() {
    TASK_NUM task = TASK_3;

    switch (task) {
        case TASK_1: {
            char to_reverse[] = "Apples";
            int string_len = strlen(to_reverse);

            printf("Before: %s\n\n", to_reverse);

            reverse_string(to_reverse, string_len, 0);

            printf("\nAfter:  %s\n\n", to_reverse);

            break;
        }
        case TASK_2: {
            int to_sum = 1010101;

            printf("Number: %d, sum of digits: %d\n", to_sum, sum_digits(to_sum));
            
            break;
        }
        case TASK_3: {
            char maze[8][8] = {
                {'X', ' ', 'X', 'X', 'X', 'X', 'X', 'X'},
                {'X', ' ', ' ', ' ', 'X', ' ', ' ', 'X'},
                {'X', 'X', 'X', ' ', 'X', ' ', 'X', 'X'},
                {'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X'},
                {'X', ' ', 'X', 'X', 'X', ' ', ' ', 'X'},
                {'X', ' ', ' ', ' ', 'X', 'X', ' ', 'X'},
                {'X', 'X', 'X', ' ', ' ', 'X', ' ', 'X'},
                {'X', 'X', 'X', 'X', 'X', 'X', ' ', ' '}
            };

            PATH_COORD moves[MAX_MOVES];
            MoveDecider moveDecider = CARDINAL_INDEX_ASC;
            int step_count = 0;

            place_initial_step(maze, moves, 1, 0);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            walk_maze(maze, moves, &step_count, moveDecider);
            
            break;
        }
        case TASK_4: {
            break;
        }
        default: break;
    }
    
    return 0;
}
