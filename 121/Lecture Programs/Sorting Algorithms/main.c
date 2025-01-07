/*
yeah
*/

#include "sorting.h"

int main() {
    int student_IDs[10] = {35, 12, 47, 89, 23, 54, 68, 13, 71, 44};

    printf("Original:\n");
    print_array(student_IDs, 10);

    selection_sort(student_IDs, 10);
    printf("Final:\n");
    print_array(student_IDs, 10);
}