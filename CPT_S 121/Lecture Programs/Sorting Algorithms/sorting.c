/*
yeah
*/

#include "sorting.h"

void print_array(int array[], int size) {
    printf("{");

    for (int i = 0; i < size; i++) {
        if (i == size-1) printf("%d", array[i]);
        else printf("%d, ", array[i]);
    }

    printf("}\n");
}

int find_max_index(int array[], int size) {
    int max = 0, max_pos = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max_pos = i;
            max = array[i];
        }
    }

    return max_pos;
}

void selection_sort(int to_sort[], int size) {
    int max;
    int max_pos;
    int unsorted_bound_incl = size-1;

    for (int j = 0; j <= size-1; j++) {
        max = -1;
        max_pos = -1;

        for (int i = 0; i <= unsorted_bound_incl; i++) {
            if (to_sort[i] > max) {
                max = to_sort[i];
                max_pos = i;
            }

            if (i == unsorted_bound_incl) {
                int tmp = to_sort[i];
                to_sort[i] = max;
                to_sort[max_pos] = tmp;
            }
        }

        unsorted_bound_incl -= 1;
    }
}