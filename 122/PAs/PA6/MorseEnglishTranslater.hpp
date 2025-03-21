#pragma once

#include "BST.hpp"
#include <stdlib.h>

// simple wrapper class for English -> Morse translation
class MorseEnglishTranslater {
	
private:
	// binary tree for lookups
	const BST tree;

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