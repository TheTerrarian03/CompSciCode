#include "lstring.h"

// basic input/output functions - single character
int my_fgetc(FILE *stream) {
    char ch;

    if (fread(&ch, 1, 1, stream) == 1) {
        return (int)ch;  // return character read if successful
    }

    return MY_EOF;  // return MY_EOF if unsuccessful
}
int my_fputc(int c, FILE *stream) {
    if (fwrite(&c, 1, 1, stream) == 1) {
        return c;  // return character written if successful
    }

    return MY_EOF;  // return MY_EOF is unsuccessful
}
int my_getchar(void) {
    return my_fgetc(stdin);
}
int my_putchar(int c) {
    return my_fputc(c, stdout);
}

// more advanced input/output functions - strings
char *my_fgets(char *s, int n, FILE *stream) {
    // NOTE: If trying to read "aaa", passing in 3 for n will
    // only read "aa". You'll need to pass in 1 more than what
    // is needed due to null character.

    // return if s is not a valid array,
    // or reading too few characters
    if (s == NULL || n <= 1) return NULL;

    int chars_read = 0;
    char next;

    do {
        next = my_fgetc(stream);

        if (next == MY_EOF) {
            // if error processing, append null char and return null pointer
            *(s+chars_read) = '\0';
            return NULL;
        }

        *(s+chars_read) = next;  // append character read to next spot in string

        chars_read++;  // increment index

        printf("Chars read: %d\n", chars_read);

        if (next == '\n') break;  // break loop if newline found
    } while (chars_read < n-1);  // only read at most n-1 characters

    *(s+chars_read) = '\0';

    return s;
}
int my_fputs(const char *s, FILE *stream) {
    // return MY_EOF if the input string or the output stream
    // isn't a valid string or stream, respectively
    if (s == NULL || stream == NULL) return MY_EOF;
    
    int chars_written = 0;
    char next = *s;
    
    while (next != '\0') {
        int result = my_fputc(next, stream);

        // return MY_EOF if unsuccessful write
        if (result == MY_EOF) return MY_EOF;

        chars_written++;
        next = *(s+chars_written);
    }

    return chars_written;
}
char *my_gets(char *s) {
    // although not explicitly stated, I thought it may
    // be a good idea to return MY_EOF if the string array
    // isn't a valid place to store characters
    if (s == NULL) return MY_EOF;

    int idx = 0;
    char next = my_getchar();
    
    while (next != '\n') {
        *(s+idx) = next;
        idx++;
        next = my_getchar();
    }

    return s;
}
int my_puts(const char *s) {
    int chars_written = 0;
    char next = *s;

    while (next != '\0') {
        my_putchar(next);

        chars_written++;
        next = *(s+chars_written);
    }

    return chars_written;
}

// string manipulation functions
char *my_strcpy(char *destination, const char *source) {
    int idx = 0;

    // copy up to the null character
    while (*(source+idx) != '\0') {
        *(destination+idx) = *(source+idx);
        idx++;
    }

    // copy the null character
    *(destination+idx) = '\0';

    return destination;
}
char *my_strncpy(char *destination, const char *source, int n) {
    int idx = 0;
    int at_src_end = 0;

    for (; idx < n; idx++) {
        if (at_src_end) {
            *(destination+idx) = '\0';
            printf("Wrote null char to index %d\n", idx);
        } else {
            char next = *(source+idx);

            *(destination+idx) = next;

            printf("Wrote char %c to index %d\n", next, idx);

            if (next == '\0') at_src_end = 1;
        }
    }

    return destination;
}
char *my_strcat(char *destination, const char *source) {
    int offset = 0, src_idx = 0;

    for (; *(destination+offset) != '\0'; offset++);  // find end index of destination array

    for (; *(source+src_idx) != '\0'; src_idx++) *(destination+offset+src_idx) = *(source+src_idx);  // append source char to dest

    *(destination+offset+src_idx) = '\0';  // add null char at end

    return destination;
}
char *my_strncat(char *destination, const char *source, int n) {
    int offset = 0, src_idx = 0;

    for (; *(destination+offset) != '\0'; offset++);  // find end index of destination array

    for (; *(source+src_idx) != '\0' && src_idx < n; src_idx++) *(destination+offset+src_idx) = *(source+src_idx);  // append source char to dest

    *(destination+offset+src_idx) = '\0';  // add null char at end

    return destination;
}
int my_strcmp(const char *s1, const char *s2) {
    int s1_end = 0, s2_end = 0;
    int idx = 0;
    
    while (1) {
        char first = *(s1+idx);
        char second = *(s2+idx);

        if (first == '\0') s1_end = 1;
        if (second == '\0') s2_end = 1;

        if (first < second) return -1;
        if (first > second) return 1;

        if (s1_end && s2_end) break;

        idx++;
    }

    return 0;
}
int my_strncmp(const char *s1, const char *s2, int n) {
    int s1_end = 0, s2_end = 0;
    int idx = 0;
    
    while (idx < n) {
        char first = *(s1+idx);
        char second = *(s2+idx);

        if (first == '\0') s1_end = 1;
        if (second == '\0') s2_end = 1;

        if (first < second) return -1;
        if (first > second) return 1;

        if (s1_end && s2_end) break;

        idx++;
    }

    return 0;
}
int my_strlen(const char *s);
