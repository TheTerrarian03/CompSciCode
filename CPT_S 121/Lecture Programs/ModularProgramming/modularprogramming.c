/*
yeah
*/

#include "modularprogramming.h"

void divide(int n1, int n2, int *result_ptr, int *remainder_ptr) {
    *result_ptr = n1 / n2;
    *remainder_ptr = n1 % n2;
}