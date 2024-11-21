#ifndef DISPLAY_H
#define DISPLAY_H

/* ---------- Definitions ---------- */
#define _CRT_SECURE_NO_WARNINGS

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

/* ---------- Inludes ---------- */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ---------- System Calls ---------- */
// Name: clr_screen
// Description: clears the screen, depending on which OS you're on
void clr_screen();

#endif
