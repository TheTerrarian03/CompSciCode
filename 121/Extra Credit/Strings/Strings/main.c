/*
Name: Logan Meyers
Date: 12/13/2024
TA: James (he was awesome btw)
Assignment: Strings (Bonus)

Description: These are my custom, ground-up (mostly) functions to replace some of the
             basic functions for file and stream reading and writing, along with some
             string functions. Enjoy!
*/

#include "lstring.h"

int main() {
    // my_getchar test
    printf("Enter a character and then press enter:\n$ ");
    char inp = my_getchar();
    my_getchar();
    printf("Got character: '%c'\n", inp);

    printf("\n");

    // my_gets tests
    printf("Enter 2 sentences (up to 80 characters each):\n$ ");
    char inp2[80] = {};
    char inp3[80] = {};
    my_gets(inp2);
    printf("$ ");
    my_gets(inp3);
    printf("\n");
    printf("Got sentence: \"%s\"\n", inp2);
    printf("Got sentence: \"%s\"\n", inp3);

    printf("\n");

    // my_fputs and fputc tests
    FILE *outfile = fopen("output.txt", "w");
    my_fputs(inp2, outfile);
    my_fputc('\n', outfile);
    my_fputs(inp3, outfile);
    fclose(outfile);

    printf("Wrote your sentences to output.txt!\n");

    // my_fgets tests
    FILE *infile = fopen("output.txt", "r");
    char finp[80] = {};
    char finp2[80] = {};
    my_fgets(finp, 80, infile);
    my_fgets(finp2, 80, infile);
    fclose(infile);

    printf("Got sentences from file:\n1. %s2. %s\n", finp, finp2);

    // fgetc test
    FILE *infile2 = fopen("output.txt", "r");
    char first = my_fgetc(infile2);
    fclose(infile);

    printf("First character from the file: '%c'\n", first);

    printf("\n");

    // all str func tests
    printf("Please enter two sentences you'd like to compare! (up to 80 chars each)\n$ ");
    char comp[80] = {};
    char comp2[80] = {};
    my_gets(comp);
    printf("$ ");
    my_gets(comp2);
    char cpy[160] = {};
    printf("STRCPY:   Original string: %s\n", cpy);
    my_strcpy(cpy, comp);
    printf("STRCPY:   After copying your first sentence: %s\n", cpy);
    my_strncpy(cpy, comp, 5);
    printf("STRNCPY:  After copying only first 5 from 1st sentence: %s\n", cpy);
    my_strcat(cpy, comp);
    printf("STRCAT:   After concatenating 1st sentence: %s\n", cpy);
    my_strncat(cpy, comp2, 2);
    printf("STRNCAT:  After concatenating only first 2 from 2nd sentence: %s\n", cpy);
    printf("\n");
    printf("STRCMP:   Result of comparing your strings: %d\n", my_strcmp(comp, comp2));
    printf("STRNCOMP: Result of comparing first 2 characters of your string: %d\n", my_strncmp(comp, comp2, 2));
    printf("\n");
    printf("STRLEN:   Length of your first  string: %d\n", my_strlen(comp));
    printf("STRLEN:   Length of your second string: %d\n", my_strlen(comp2));
}
