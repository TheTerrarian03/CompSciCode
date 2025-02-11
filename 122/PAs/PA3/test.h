/*
- Name: Logan Meyers
- TA: Martin "Double Factorial" Hundrup
- Assignment: PA 3
- [Mostly] Finished: 02/10/2025
- Description: Digital Music Manager!

- File: test.h
- Description: headers and declerations for my few test functions
*/

#ifndef TEST_H
#define TEST_H

#include "pa3.h"

/*
 * Function: test_insert
 * --------------------
 *   Tests the functionality of the insertAtFront function
*/
void test_insert();

/*
 * Function: test_delete
 * --------------------
 *   Tests the functionality of the remove_song function
*/
void test_delete();

/*
 * Function: test_shuffle
 * --------------------
 *   Tests the functionality of the shuffle_menu function
 * 
 *   Doesn't work. Don't even try
*/
// void test_shuffle();

/*
 * Function: test_all
 * --------------------
 *   Runs all (implemented) test functions
*/
void test_all();

#endif