/*
yeah
*/

#include "modularprogramming.h"

int main() {
    int array_ints[5] = {1, 2, 3, 4, 5};

    print_array(array_ints, sizeof(array_ints)/4);

    init_array(array_ints, 6);

    print_array(array_ints, sizeof(array_ints)/4);

    return 0;
}
