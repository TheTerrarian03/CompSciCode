/*
- File: MorseEnglishTranslater.cpp
- Description: Function definitions for the MorseEnglishTranslater.hpp file

- Modified: 03/23/2025
*/

#pragma once

#include "MorseEnglishTranslater.hpp"

void MorseEnglishTranslater::run() {
	std::string option = "";

	do {
		system("cls");

		std::cout << "Please choose an option:" << std::endl
			<< "  1. Convert file" << std::endl
			<< "  2. Convert custom text" << std::endl
			<< "  3. Quit" << std::endl << std::endl
			<< "> ";

		std::cin >> option;

		if (option[0] == '1') {
			convertFile();
			system("pause");
		}
		else if (option[0] == '2') {
			englishToMorse(askConvert());
			system("pause");
		}
		else if (option[0] == '3') {
			std::cout << "Goodbye!" << std::endl;
			return;
		}
	} while (option[0] != '3');
}

std::string MorseEnglishTranslater::askConvert() {
	std::cout << "Please enter what you want to convert below." << std::endl
		<< "and enter \"-1\" alone in a new line when you are done." << std::endl << std::endl;

	std::string text = "";

	std::string input = "";

	while (input != "-1") {
		std::cin >> input;

		if (input[0] != '-' && input[1] != '1') {
			text.append(input);
			text.append("\n");
		}
	}

	return text;
}

void MorseEnglishTranslater::convertFile() {
	std::ifstream infile("Convert.txt");

	if (!infile.is_open()) {
		std::cerr << "Error opening Convert.txt file!" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(infile, line)) {
		englishToMorse(line);
	}

	infile.close();
}

void MorseEnglishTranslater::englishToMorse(std::string input) {
	for (int i = 0; i < input.length(); i++) {
		char currChar = input[i];

		// lowercase to uppercase handled in lookup! (MorseFuncs.hpp, charToID())
		Morse morse_to_print = tree.search(currChar);

		if (currChar == ' ') std::cout << "   ";
		else if (currChar == '\n') std::cout << std::endl;
		else std::cout << morse_to_print << ' ';
	}

	std::cout << std::endl;
}
