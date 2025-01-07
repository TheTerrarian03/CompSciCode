#include "lab9.h"

// Task 1
char *string_reverse_arrnot(char *src) {
    // first, get the length of the string, not including the null char
    int length = my_strln(src);

    // second, iterate through half of the array's length, 
    // swapping the first and last values offset by i
    for (int i = 0; i <= length/2; i++) {
        int right_indx = length - 1 - i;

        char tmp = src[right_indx];
        src[right_indx] = src[i];
        src[i] = tmp;
    }

    // return the pointer to the array
    return src;
}
char *string_reverse_ptrnot(char *src) {
    // first, get the length of the string, not including the null char
    int last_idx = my_strln(src);

    // second, iterate through half of the array's length, 
    // swapping the first and last values offset by i
    for (int i = 0; i <= last_idx/2; i++) {
        int right_indx = last_idx - 1 - i;

        char tmp = *(src + right_indx);
        *(src + right_indx) = *(src + i);
        *(src + i) = tmp;
    }

    // return the pointer to the array
    return src;
}

// Task 2

// copies all chars from the source to the destination
char *my_strcpy(char *destination, const char *source) {
    int length = my_strln_wnull(source);
    for (int i = 0; i < length; i++) {
        destination[i] = source[i];
    }

    return destination;
}
char *my_strcat(char *destination, const char *source) {
    int last_idx = my_strln_wnull(destination);
    int source_len = my_strln_wnull(source);

    for (int i = 0; i < source_len; i++) {
        destination[last_idx + i] = source[i];
    }

    return destination;
}
// -1 if s1 < s2
// 0  if s1 == s2
// 1  else
int my_strcmp(char *s1, char *s2) {
    int s1_len = my_strln(s1);
    int s2_len = my_strln(s2);

    int max_len = (s1_len > s2_len) ? s1_len : (s2_len > s1_len) ? s2_len : s1_len;

    for (int i = 0; i < max_len; i++) {
        if (s1[i] < s2[i]) return -1;
        if (s1[i] > s2[i]) return 1;
    }

    if (s1_len == s2_len) return 0;

    return 1;
}
int my_strln(char *s) {
    int length = 0;
    for (; s[length] != '\0'; ++length);
    return length;
}
int my_strln_wnull(char *s) {
    return my_strln(s) + 1;
}
