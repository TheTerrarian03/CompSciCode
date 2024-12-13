/*
NO ARRAY NOTATION - ONLY POINTER NOTATION
*/

#include "lstring.h"

int main() {
    // FILE *infile = fopen("test.txt", "r");

    // char str1[10];

    // my_fgets(&str1, 5, infile);

    // for (int i=0; i < 10; i++) {
    //     printf("Char: '%c' or '%d'\n", str1[i], str1[i]);
    // }

    // printf("Read string: %s\n", str1);

    // fclose(infile);

    // FILE *outfile = fopen("test.txt", "w");

    // char *to_write = "Hello world!\n";

    // int written = my_fputs(to_write, outfile);

    // printf("Num written chars: %d\n", written);

    // fclose(outfile);

    // int gets_res = my_getchar();

    // printf("Got: %d\n", gets_res);

    char *first = "Dog2";
    char *second = "Dog3";

    printf("Result: %d\n", my_strncmp(first, second, 3));

    return 0;
}