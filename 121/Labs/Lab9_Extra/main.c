#include "funcs.h"

int main() {
    FILE *infile = fopen("string.txt", "r");
    char *strings[100][41];
    int num_strings = 0;

    while (!feof(infile)) {
        char *sentence[41];

        for (int i=0; i<41; i++) {
            printf("%c", i);
        }
    }

    return 0;
}