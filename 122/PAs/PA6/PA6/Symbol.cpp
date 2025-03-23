/*
- File: Symbol.cpp
- Description: Function Definitions for the Symbol.hpp file

- Added: 03/23/2025
*/

#pragma once

#include "Symbol.hpp"

Symbol::Symbol() : character('\0') {}
Symbol::Symbol(char newChar) {
	if (newChar >= 'a') newChar -= 32;

	character = newChar;
}
Symbol::Symbol(const Symbol& copy) {
	char newChar = copy.character;

	if (newChar >= 'a') newChar -= 32;

	character = newChar;
}
Symbol::~Symbol() {}

char Symbol::getChar() const { return character; }
void Symbol::setChar(char newChar) { character = newChar; }

int Symbol::getID() const {
	// range of alphabet to 0-25
	if (character >= 'A' && character <= 'Z') return character - 'A';

	// range of numbers to 26-35
	if (character >= '0' && character <= '9') return character - '0' + 26;

	if (character == '.') return 36;
	if (character == ',') return 37;
	if (character == '?') return 38;

	else return 420; // bad number
}

std::ostream& operator<< (std::ostream& lhs, const Symbol& rhs) {
	lhs << rhs.getChar();
	return lhs;
}

std::istream& operator>> (std::istream& lhs, Symbol& rhs) {
	char newChar;

	lhs >> newChar;

	rhs.setChar(newChar);

	return lhs;
}

Symbol& Symbol::operator= (const Symbol& copy) {
	character = copy.getChar();
	return *this;
}

bool operator== (const Symbol& lhs, const Symbol& rhs) { return lhs.getChar() == rhs.getChar(); }
bool operator!= (const Symbol& lhs, const Symbol& rhs) { return lhs.getChar() != rhs.getChar(); }
bool operator< (const Symbol& lhs, const Symbol& rhs) { return lhs.getID() < rhs.getID(); }
bool operator> (const Symbol& lhs, const Symbol& rhs) { return lhs.getID() > rhs.getID(); }
bool operator<= (const Symbol& lhs, const Symbol& rhs) { return lhs.getID() <= rhs.getID(); }
bool operator>= (const Symbol& lhs, const Symbol& rhs) { return lhs.getID() >= rhs.getID(); }
