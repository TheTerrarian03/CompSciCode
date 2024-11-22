#include <stdio.h>
#include <stdlib.h>  // malloc(), calloc(), free()

// malloc is manual allocation of memory
// calloc is allocation of arrays, and those arrays can change
// free for 

int main() {
    int num = 0, *ptr = NULL;

    printf("How many integers would you like to allocate from the heap?\n$ ");
    scanf("%d", &num);

    while (num > 0) {
        int *ptr = malloc(sizeof(int));
        *ptr = 50;
    }

    return 0;
}