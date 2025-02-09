/*
- Name: Logan Meyers
- TA: Martin Double Factorial
- Assignment: PA 2
- "Finished": 01/29/2025
- Description: Digital Music Manager!

- Note: Better comments and headers will be added for the third PA, next submission.

- File: pa2.c
- Description: definitions of the functions from pa2.h
*/

#include "pa3.h"

/* ----- Menu Functions ----- */

int main_menu() {
    printf("Please enter what you'd like to do with your music:\n\
    1  - Load music to file\n\
    2  - Store music to file\n\
    3  - Display the songs currently loaded\n\
    4  - Insert a song\n\
    5  - Delete a song\n\
    6  - Edit a song\n\
    7  - Sort songs\n\
    8  - Rate a song\n\
    9  - Play a song\n\
    10 - Shuffle songs\n\
    11 - Exit\n> ");

    int choice = 0;

    while (choice == 0) {
        int result = scanf("%d", &choice);

        if (result > 0) break;

        clear_stdin_buffer();

        printf("Invalid input! Try again:\n> ");
    }

    return choice;
}
int load_menu(Node **pList) {
    // open file
    FILE *infile = fopen(PLAYLIST_FILE, "r");

    // check for success MARTIN LOOK HERE haha
    if (infile == NULL) {
        printf("There was an error trying to read your file!\nPlease make sure `%s` exists.", PLAYLIST_FILE);
        return 0;
    }

    // delete existing list if there is one,
    // we want to overwrite it
    destroy_list(pList);

    // read lines and put song in the list
    char line[MAX_LINE_LEN] = {};
    while (fgets(line, sizeof(line), infile) != NULL) {
        Record new_record = {};

        record_from_line(&new_record, line);
        
        insert_front(pList, new_record);
    }

    return 1;
}
void store_menu(Node *pList) {
    // make sure there is data to write
    if (pList == NULL || get_list_length(pList) == 0) {
        printf("You have no songs loaded! Canceling store operation.\n");
        return;
    }

    // open the file as write, which would create the file if it
    // doesn't exist MARTIN haha
    FILE *outfile = fopen(PLAYLIST_FILE, "w");

    // write records to file
    while (pList != NULL) {
        store_song_to_playlist(pList->data, outfile);
        pList = pList->pNext;
    }

    fclose(outfile);
}
void display_menu(Node *pList) {
    printf("You have %d songs:\n", get_list_length(pList));

    int cur_num = 1;
    while (pList != NULL) {
        printf("%3d - \"%s\" by \"%s\" [%s]\n        (%s), %d:%d, %d plays, %d/5 rating\n\n",
            cur_num,
            pList->data.song,
            pList->data.artist,
            pList->data.album,
            pList->data.genre,
            pList->data.length.minutes,
            pList->data.length.seconds,
            pList->data.num_plays,
            pList->data.rating);
        
        pList = pList->pNext;
        cur_num++;
    }
}
// void insert_menu();
// void delete_menu();
void edit_menu(Node *pList) {
    printf("!! THIS HAS NOT BEEN IMPLEMENTED AND MAY NOT WORK AT ALL !!\n");

    printf("What artist would you like to seach for? (Case-sensitive)\n> ");

    char artist[MAX_NAME_LEN] = "";
    cpy_clean_nstring(artist, MAX_NAME_LEN);

    printf("Got artist: \"%s\"\n", artist);

    // check to see if artist exists in playlist
    int artist_exists = get_artist_exists(pList, artist);
    if (!artist_exists) {
        printf("That artist doesn't exist! Please try searching by another artist.\n");
        return;
    }

    // show songs that match artist
    int num_matching = print_songs_matching_artist(pList, artist);

    printf("Please enter the number song you'd like to edit (1-%d)\n> ", num_matching);

    int song_num = 0;

    while (song_num < 1 || song_num > num_matching) {
        int result = scanf("%d", &song_num);

        if (result > 0 && song_num >= 1 && song_num <= num_matching) break;

        if (result > 0) {
            printf("Number out of range! Try again:\n> ");
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Invalid input! Try again:\n> ");
    }

    Node *song_to_edit = get_nth_song_of_artist(pList, artist, song_num);

    printf("Please enter the new values you'd like for each field below.\n");
    printf("NOTE: These are taken literally and there will be no redos.\n");
    printf("NOTE: entering nothing and just pressing enter will skip and keep current value\n");
    printf("Anything that should be a number but is a character is converted with 0 as default.\n");

    char input[MAX_NAME_LEN] = "";
    
    printf("Artist => ");
    cpy_nstring_if_exist(song_to_edit->data.artist, MAX_NAME_LEN);
    printf("Artist: %s\n", song_to_edit->data.artist);
    printf("Album => ");
    cpy_nstring_if_exist(song_to_edit->data.album, MAX_NAME_LEN);
    printf("Album: %s\n", song_to_edit->data.album);
    printf("Song => ");
    cpy_nstring_if_exist(song_to_edit->data.song, MAX_NAME_LEN);
    printf("Genre => ");
    cpy_nstring_if_exist(song_to_edit->data.genre, MAX_NAME_LEN);

    printf("Times played => ");
    set_int_in_range_if_exist(&(song_to_edit->data.num_plays), 0, __INT32_MAX__);

    printf("Rating (1-5) => ");
    set_int_in_range_if_exist(&(song_to_edit->data.rating), 1, 5);
}
// void sort_menu();
void rate_menu(Node **pList) {
    printf("What song would you like to rate? (Case-sensitive)\n> ");

    char song[MAX_NAME_LEN] = "";
    cpy_clean_nstring(song, MAX_NAME_LEN);

    // check to see if song exists in playlist
    Node *song_node = get_song_node(*pList, song);
    if (song_node == NULL) {
        printf("That song doesn't exist! Please try rating another song.\n");
        return;
    }

    printf("Please enter the rating you'd like to give \"%s\": (1-5)\n> ", song);
    int rating = 0;

    while (rating < 1 || rating > 5) {
        int result = scanf("%d", &rating);

        if (result > 0 && rating >= 1 && rating <= 5) break;

        if (result > 0) {
            printf("Rating out of range! Try again:\n> ");
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Invalid input! Try again:\n> ");
    }

    song_node->data.rating = rating;

    printf("Successfully gave song \"%s\" rating %d.\n", song, rating);
}
void play_menu();
// void shuffle_menu();
void exit_menu();

/* ----- File reading/writing ----- */

void store_song_to_playlist(Record song, FILE *outfile) {
    char tmp[MAX_NAME_LEN+2] = "";
    
    // artist
    string_to_file_format(tmp, song.artist);
    fprintf(outfile, "%s,", tmp);

    // album
    string_to_file_format(tmp, song.album);
    fprintf(outfile, "%s,", tmp);

    // song
    string_to_file_format(tmp, song.song);
    fprintf(outfile, "%s,", tmp);

    // genre
    string_to_file_format(tmp, song.genre);
    fprintf(outfile, "%s,", tmp);

    // other num stats
    fprintf(outfile, "%d:%d,%d,%d\n",
        song.length.minutes,
        song.length.seconds,
        song.num_plays,
        song.rating);
}

/* ----- Data Parsing Functions ----- */

void string_to_file_format(char dest[MAX_NAME_LEN+2], char *src) {
    // check if there is a comma in the string to write
    char *comma_pos = strchr(src, ',');
    if (comma_pos) {
        strcpy(dest, "\"");
        strncat(dest, src, MAX_NAME_LEN);
        strcat(dest, "\"");
    } else {
        strncpy(dest, src, MAX_NAME_LEN);
    }
}
// for this function, I had to use a little ChatGPT to help get past some errors I was stuck on.
// originally, I was just using strtok and strcpy but the way strtok works,
// I was unable to get the pointer to the next portion of the line. So, with a little help,
// this is what I've come up with:
char *extract_string(char dest[MAX_NAME_LEN], char *line) {
    char *start = line;

    if (*start == '"') {
        start++;  // move past first quote
        char *end = strchr(start, '"');  // find next ending quote
        if (end) {
            strncpy(dest, start, end - start);  // copy string to dest without quotes
            return end + 2;  // return pointer to next character, after quote and comma
        }
    } else {
        char *end = strchr(line, ',');  // find next comma
        if (end) {
            strncpy(dest, start, end - start);  // copy string to dest
            return end + 1;  // return pointer to next character, after comma
        }
    }

    // if all else fails, cry, but just return NULL
    return NULL;
}

void record_from_line(Record *to_store, char line[MAX_LINE_LEN]) {
    char artist[MAX_NAME_LEN] = "", album[MAX_NAME_LEN] = "", song[MAX_NAME_LEN] = "", genre[MAX_NAME_LEN] = "";

    // read artist, album, song, and genre
    char *next = extract_string(to_store->artist, line);
    if (next) next = extract_string(to_store->album, next);
    if (next) next = extract_string(to_store->song, next);
    if (next) next = extract_string(to_store->genre, next);

    // get other number stats
    if (next) {
        Duration len = {.minutes = atoi(strtok(next, ":")),
                        .seconds = atoi(strtok(NULL, ","))};
        to_store->length = len;

        to_store->num_plays = atoi(strtok(NULL, ","));
        to_store->rating = atoi(strtok(NULL, ",\n\0"));
    }
}

/* ----- Doubly Linked List Functions ---- */

void init_list(Node **pList) {
    *pList = NULL;
}
Node *create_node(Record new_data) {
    // try to allocate space for a new Node
    Node *pMem = malloc(sizeof(Node));

    // set attributes if it exists
    if (pMem != NULL) {
        pMem->pNext = NULL;
        pMem->pPref = NULL;
        pMem->data = new_data;
    }

    // return a possibly NULL pointer to a Node
    return pMem;
}
int insert_front(Node **pList, Record new_data) {
    Node *pMem = create_node(new_data);
    int success = 0;

    if (pMem != NULL) {
        success = 1;

        // if list is empty, set *pList to pMem
        if (*pList == NULL) {
            *pList = pMem;
        }
        // otherwise add to front and adjust links
        else {
            pMem->pNext = *pList;
            (pMem->pNext)->pPref = pMem;
            *pList = pMem;
        }
    }

    return success;
}
void destroy_list(Node **pList) {
    // recursive step
    if (*pList != NULL) {
        destroy_list(&(*pList)->pNext);
        printf("freeing song %s\n", (*pList)->data.song);
        free(*pList);
        *pList = NULL;
    }
}
int get_list_length(Node *pList) {
    int len = 0;
    while (pList != NULL) {
        len++;
        pList = pList->pNext;
    }
    return len;
}
Node *get_song_node(Node *pList, char *name) {
    if (pList == NULL) return NULL;

    if (strcmp(pList->data.song, name) == 0) return pList;

    return get_song_node(pList->pNext, name);
}
int get_artist_exists(Node *pList, char *artist) {
    if (pList == NULL) return 0;

    if (strcmp(pList->data.artist, artist) == 0) return 1;

    return get_artist_exists(pList->pNext, artist);
}
int print_songs_matching_artist(Node *pList, char *artist) {
    int cur_num = 1;

    while (pList != NULL) {
        if (strcmp(pList->data.artist, artist) == 0) {
            printf("%3d - \"%s\" by \"%s\" [%s]\n        (%s), %d:%d, %d plays, %d/5 rating\n\n",
                cur_num,
                pList->data.song,
                pList->data.artist,
                pList->data.album,
                pList->data.genre,
                pList->data.length.minutes,
                pList->data.length.seconds,
                pList->data.num_plays,
                pList->data.rating);
            
            cur_num++;
        }

        pList = pList->pNext;
    }

    return cur_num-1;
}
Node *get_nth_song_of_artist(Node *pList, char *artist, int n) {
    int cur_num = 1;

    while (pList != NULL) {
        if (strcmp(pList->data.artist, artist) == 0) {
            if (cur_num == n) return pList;  // current in artist matching n
            
            cur_num++;
        }

        pList = pList->pNext;
    }

    // return NULL if nth song doesn't exist
    return NULL;
}
void print_list(Node *pList) {
    if (pList == NULL) {
        printf("-->\n");
    } else {
        printf("--> \"%s\" by \"%s\" ", pList->data.song, pList->data.artist);
        print_list(pList->pNext);
    }
}
void print_list_p(Node *pList) {
    if (pList == NULL) {
        putchar('\n');
    } else {
        printf("[%p <-- %p --> %p]\n", pList->pPref, pList, pList->pNext);
        print_list_p(pList->pNext);
    }
}

/* ----- Input Helper Functions ----- */

// this is straight from chatGPT because I am FED UP WITH
// not being able to easily clear the stdin buffer
// so you can make sure you're getting good data.
// Trust me, I've tried SO MUCH to get a function
// that behaves like this one... but I finally gave up.
void clear_stdin_buffer() {
    #ifdef _WIN32
        // Check if there is data available to read
        if (_kbhit()) {
            // If there is data, clear the buffer
            while (getchar() != '\n' && !feof(stdin));
        }
        // If the buffer is empty, do nothing
    #else
        fd_set read_fds;
        struct timeval timeout;
    
        // Set up the file descriptor set
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);
    
        // Set timeout to 0 to make it non-blocking
        timeout.tv_sec = 0;
        timeout.tv_usec = 0;
    
        // Check if there is data available to read
        if (select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout) > 0) {
            // If there is data, clear the buffer
            while (fgetc(stdin) != '\n' && !feof(stdin));
        }
        // If the buffer is empty, do nothing
    #endif
}

void cpy_clean_nstring(char *dest, int n) {
    clear_stdin_buffer();
    // ungetc('a', stdin);
    // if (fgets(dest, n, stdin) == NULL) {
    //     printf("Error reading input or EOF reached.\n");
    //     exit(1);
    // }
    // // Remove the newline character if present
    // dest[strcspn(dest, "\n")] = '\0';

    ungetc('a', stdin);
    int c;
    int i=0;
    scanf("%s", dest);
}

void cpy_nstring_if_exist(char *dest, int n) {
    clear_stdin_buffer();

    int c = getchar();

    if (c == '\n') return;

    dest[0] = c;
    int i = 1;

    while ((c = getchar()) != '\n' && c != EOF && i < n-1) {
        dest[i] = c;
        i++;
    }
    dest[i] = '\0';
}

void set_int_in_range_if_exist(int *num, int min, int max) {
    int input = min;

    int result = scanf("%d", &input);

    if (result == 0) return;

    if (input < min || input > max) {
        // number out of range, skip
        return;
    }

    *num = input;
}