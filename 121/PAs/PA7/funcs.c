#include "funcs.h"

/* ----- Display ----- */
void clr_screen() {
    system(CLEAR_COMMAND);
}

/* ----- Random ----- */
void seed_rand() {
    srand((unsigned int) time(NULL));
}
int rand_range(int range) {
    return rand() % range;
}

/* ----- Array Manipulation ---- */
void selection_sort(int to_sort[], int length) {
    // run length-1 sort passes
    for (int i=0; i < length - 1; i++) {
        int min_idx = i;

        // check remaining indexes for a smaller
        for (int j=i+1; j < length; j++) {
            if (to_sort[j] < to_sort[min_idx]) min_idx = j;
        }

        // swap values
        if (i != min_idx) {
            int temp = to_sort[i];
            to_sort[i] = to_sort[min_idx];
            to_sort[min_idx] = temp;
        }
    }
}
void hand_to_frequency_tables(int face_freq[4], int suit_freq[13], Card cards[5]) {
    for (int i=0; i < 5; i++) {
        face_freq[cards[i].col_idx]++;
        suit_freq[cards[i].row_idx]++;
    }
}
int get_index_of_freq(int *freqs, int len_freqs, int freq) {
    for (int i=0; i < len_freqs; i++) {
        if (*(freqs+i) == freq) return i;
    }

    return 0;
}
int get_2nd_index_of_freq(int *freqs, int len_freqs, int freq) {
    int first_found = 0;
    
    for (int i=0; i < len_freqs; i++) {
        if (*(freqs+i) == freq) {
            if (first_found == 1) return i;
            if (first_found == 0) first_found++;
        }
    }

    return 0;
}
int get_highest_freq(int *freqs, int len_freqs) {
    int highest = 0;


    for (int i=0; i < len_freqs; i++) {
        if (*(freqs+i)) highest = i;
    }

    return highest;
}