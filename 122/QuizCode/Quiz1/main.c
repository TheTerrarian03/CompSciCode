#include <stdio.h>

void printIntArr(int *arr, int n);
char *myStrncpy(char *destination, const char *source, int n);
char *strCpyRec(char *destination, const char *source);
void bubble_sort(int *arr, int len);

int main() {
    // myStrncpy
    char dest1[11] = {'a', 'b', 'c', 'd', 'e'};
    char *src1 = "cat";
    
    myStrncpy(dest1, src1, 10);
    printf("After myStrncpy: \"%s\"\n", dest1);
    
    // strCpyRec
    putchar('\n');

    char dest2[10];
    char *src2 = "bananananana";

    strCpyRec(dest2, src2);
    printf("After strCpyRec: \"%s\"\n", dest2);

    // bubble sort
    int bubbles[12] = {1,5, 3, 6, 2, 6, 8, 4, 7, 4, 6, 7};
    printf("Before sort: ");
    printIntArr(bubbles, 12);

    bubble_sort(bubbles, 12);

    printf("After sort:  ");
    printIntArr(bubbles, 12);
    putchar('\n');

    return 0;
}

void printIntArr(int *arr, int n) {
    putchar('[');
    for (int i=0; i < n; i++) {
        printf("%d%s", arr[i], i < n-1 ? ", " : "");
    }
    putchar(']');
    putchar('\n');
}

char *myStrncpy(char *destination, const char *source, int n) {
    // current position and character to copy
    int i=0;
    char c = source[i];

    // copy characters from source to destination,
    // looking for source's null char in order to stop
    while (c != '\0') {
        destination[i] = c;
        c = source[++i];
    }

    // fill remaining, if needed, with null
    for (; i < n; i++) {
        destination[i] = '\0';
    }

    // return dest pointer
    return destination;
}

char *strCpyRec(char *destination, const char *source) {
    *destination = *source;

    if (*source == '\0') return destination;

    strCpyRec(destination+1, source+1);
}

void bubble_sort(int *arr, int len) {
    int u = len-1;  // step 1

    while (u > 0) {  // step 2
        int c = 1;   // step 3

        while (c <= u) {  // step 4
            // step 5
            if (arr[c] < arr[c-1]) {
                int tmp = arr[c-1];
                arr[c-1] = arr[c];
                arr[c] = tmp;
            }

            c++;  // haha, step 6
        }

        u--;  // step 7
    }
}
