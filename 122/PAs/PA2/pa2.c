#include "pa2.h"

/* ----- Menu Functions ----- */

int main_menu() {
    printf("Please enter what you'd like to do with your music:\n\
    1  - Load music to file\n\
    2  - Store music to file\n\
    3  - Display the songs currently loaded\n\
    6  - Edit a song\n\
    8  - Rate a song\n\
    9  - Play a song\n\
    11 - Exit\n> ");

    int choice = 0;

    while (choice == 0) {
        int result = scanf("%d", &choice);

        if (result > 0) break;

        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        printf("Invalid input! Try again:\n> ");
    }

    return choice;
}
int load_menu(Node **pList) {
    // open file
    FILE *infile = fopen(PLAYLIST_FILE, "r");

    // check for success MARTIN LOOK HERE
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
void edit_menu();
// void sort_menu();
void rate_menu();
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
            // unecessary?: dest[end - start] = '\0';  // null-terminate
            return end + 2;  // return pointer to next character, after quote and comma
        }
    } else {
        char *end = strchr(line, ',');  // find next comma
        if (end) {
            strncpy(dest, start, end - start);  // copy string to dest
            // unecessary code here too?
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
