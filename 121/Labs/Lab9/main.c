#include "lab9.h"

int main() {
    // Task 1
    char source1[100] = {'C', 'p', 't', 'S', ' ', 'i', 's', ' ', 'c', 'o', 'o', 'l', '!', '\0'};

    printf("----- Task 1 - Array Notation: -----\n");
    printf("Old String: %s\n", source1);
    string_reverse_arrnot(source1);
    printf("New String: %s\n", source1);
    
    char source2[100] = {'J', 'a', 'm', 'e', 's', ' ', 'i', 's', ' ', 'a', 'w', 'e', 's', 'o', 'm', 'e', '!', '\0'};

    printf("\n----- Task 1 - Pointer Notation: -----\n");
    printf("Old String: %s\n", source2);
    string_reverse_ptrnot(source2);
    printf("New String: %s\n", source2);

    // Task 2
    char source3[100] = {'C', 'o', 'p', 'y', ' ', 'm', 'e', 'e', 'e', 'e', '!', '\0'};
    char dest1[100] = {0};

    printf("\n----- Task 2 - my_strcpy -----\n");
    printf("Source String: %s\n", source3);
    printf("Dest string BEFORE: \"%s\"\n", dest1);
    my_strcpy(dest1, source3);
    printf("Dest string AFTER: \"%s\"\n", dest1);

    char to_append[100] = {'A', 'b', 'i', 't', 'r', 'i', 'a', '\0'};
    char dest2[100] = {'J', 'a', 'm', 'e', 's', '\0'};

    printf("\n----- Task 2 - my_strcat -----\n");
    printf("Destination BEFORE: %s\n", dest2);
    printf("String To Append: \"%s\"\n", to_append);
    my_strcat(dest2, to_append);
    printf("Dest string After: \"");
    for (int i = 0; i < 100; i++) {
        printf("%c", dest2[i]);
    }
    printf("\"\n");

    char cat[100] = {'c', 'a', 't', '\0'};
    char dog[100] = {'d', 'o', 'g', 's', '\0'};
    char giraffe[100] = {'g', 'i', 'r', 'a', 'f', 'f', 'e', '\0'};

    printf("\n----- Tast 2 - my_strcmp (str1 < str2) -----\n");
    printf("First String: %s\n", cat);
    printf("Second String: %s\n", dog);
    int result = my_strcmp(cat, dog);
    printf("Result: %d\n", result);

    printf("\n----- Tast 2 - my_strcmp (str1 > str2) -----\n");
    printf("First String: %s\n", dog);
    printf("Second String: %s\n", cat);
    result = my_strcmp(dog, cat);
    printf("Result: %d\n", result);

    printf("\n----- Tast 2 - my_strcmp (str1 = str2) -----\n");
    printf("First String: %s\n", cat);
    printf("Second String: %s\n", cat);
    result = my_strcmp(cat, cat);
    printf("Result: %d\n", result);
}