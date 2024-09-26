/*
- Logan Meyers
- 09/11/2024
- Score To Letter Grade example code from during lectures

- Description:
*/

#include "LetterGrade.h"

/*
>= 90 --> A
< 90 AND >= 90 --> B
*/
char determine_letter_grade(int score) {
    char letter_grade = '\0';

    if (score > 90) {
        letter_grade = 'A';
    } else if (score < 90 && score >= 80) {
        letter_grade = 'B';
    } else if (score < 80 && score >= 70) {
        letter_grade = 'C';
    } else if (score < 70 && score >= 60) {
        letter_grade = 'D';
    } else {
        letter_grade = 'F';
    }

    return letter_grade;
}
