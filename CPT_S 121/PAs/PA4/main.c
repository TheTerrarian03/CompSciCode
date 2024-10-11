/*
- Logan Meyers
- 011881121
- 10/10/2024
- PA4

- Welcome to CRAPS!
*/

#include "pa4.h"

int main() {
    double balance = get_double_safe_pos("Enter positive: ");

    printf("\n%lf", balance);

    return 0;
}