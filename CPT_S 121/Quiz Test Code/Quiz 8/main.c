#include <stdio.h>

int recursively_compute_power(int base, int exponent);

int main() {
    int b = 2, e = 16;

    printf("%d^%d = %d\n", b, e, recursively_compute_power(b, e));

    return 0;
}

// base case: exponent == 1
// returns base * power(base, exponent-1)
int recursively_compute_power(int base, int exponent) {
    if (exponent == 1) return base;
    else return base * recursively_compute_power(base, exponent-1);
}