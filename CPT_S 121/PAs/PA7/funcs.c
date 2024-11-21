#include "funcs.h"

/* ----- Random ----- */
void seed_rand() {
    srand((unsigned int) time(NULL));
}
int rand_range(int range) {
    return rand() % range;
}