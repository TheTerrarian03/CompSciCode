#include <stdio.h>
#include <string.h> // strlen() strcpy() strncpy() strcat() strncat() strcmp() strtok()

char *my_strcpy(char *dest, const char *src);

int main() {
    printf("result of strcmp: %d\n", strcmp("cat", "dog"));
    printf("result of strcmp: %d\n", strcmp("dog", "cat"));
    printf("result of strcmp: %d\n", strcmp("cat", "cat"));
    printf("result of strcmp: %d\n", strcmp("cat", "Cat"));

    

    return 0;
}

char *my_strcpy(char *dest, const char *src) {
    int index = 0;
    for (; src[index] != '\0'; ++index) {
        dest[index] = src[index];
    }
    dest[index] = '\0';

    return dest;
}