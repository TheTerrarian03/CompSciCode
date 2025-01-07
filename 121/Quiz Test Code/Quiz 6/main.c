#include <stdio.h>
#include <ctype.h>

int count_alphas(char to_count[], int num_items);
void find_min_and_max(int numbers[], int num_numbers, int *min, int *max);

int main() {
    // char chars[7] = {'1', '2', '1'};
    int numbers [16] = {0, 6, 3, 7, 2, 9, 2, 7, 3, 8, 3, 8, 3, 35, 21, -2};
    int min = 0, max = 0;

    // printf("Alphas: %d", count_alphas(chars, 7));
    find_min_and_max(numbers, 16, &min, &max);
    printf("min: %d, max: %d", min, max);

    return 0;
}

int count_alphas(char to_count[], int num_items) {
    int alphas = 0;

    for (int i=0; i < num_items; i++) {
        if (isalpha(to_count[i])) alphas++;
    }

    return alphas;
}

void find_min_and_max(int numbers[], int num_numbers, int *min, int *max) {
    // loop through all numbers
    for (int i = 0; i < num_numbers; i++) {
        // set min if numbers[i] is smaller than min
        if (numbers[i] < *min) *min = numbers[i];
        // set max if numbers [i] is bigger than max
        if (numbers[i] > *max) *max = numbers[i];
    }
}