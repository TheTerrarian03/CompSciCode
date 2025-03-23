/*
- File: MorseEnglishTranslater.hpp
- Description: Function declerations and variables for the MorseEnglishTranslater class
- MorseEnglishTranslater class: Wrapper class for main translating app

- Modified: 03/23/2025
*/

#pragma once

#include "Symbol.hpp"
#include "Morse.hpp"
#include "BST.hpp"
#include <stdlib.h>

// simple wrapper class for English -> Morse translation
class MorseEnglishTranslater {
	
private:
	// binary tree for lookups
	// could also use char and std::string instead of Symbol and Morse
	const BST<Symbol, Morse> tree;

public:
	// constructor
	MorseEnglishTranslater() : tree() {}

	// run main app, input loop
	void run();

	// ask user for custom text they want to convert to morse
	std::string askConvert();

	// convert what's in the Convert.txt file and output to screen
	void convertFile();

	// convert a given string to morse and output to screen
	// takes a std::string for input
	void englishToMorse(std::string input);
};