/*
yeah
*/

#include "modularprogramming.h"

int main() {
    int n1 = 7, n2 = 3;
    int result = 0, remainder = 0;

    divide(n1, n2, &result, &remainder);

    printf("Res: %d, Rem: %d\n", result, remainder);
    
    printf("&res: %p, &rem: %p\n", &result, &remainder);

    return 0;
}