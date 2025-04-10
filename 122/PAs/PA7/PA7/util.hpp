/*
- Name: Logan Meyers
- TA: Martin Hundrup
- Date Finished: 04-09-2025
- Program: Student Absence Manager

- File: util.hpp
- What: Header files for my utility functions
*/

#pragma once

#define _CRT_SECURE_NO_WARNINGS  // for locatime_s warning

#include <iostream>
#include <sstream>
#include <cstdlib> // for system()

/*
 * Function: clearConsole
 * --------------------
 *   clear the console! OS-dynamic
 *
*/
void clearConsole();

/*
 * Function: getDate
 * --------------------
 *   Get the current system date in MM-DD-YYYY format
 *
 *   Returns:
 *   - std::string representing the date
*/
std::string getDate();
