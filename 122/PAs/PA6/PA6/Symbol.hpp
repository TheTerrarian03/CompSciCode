/*
- File: Symbol.hpp
- Description: Function declerations and variables for the Symbol class
- Symbol class: This class holds a simple character for a symbol and the
		        functions for proper comparisons

- Added: 03/23/2025
*/

#pragma once

#include <iostream>

class Symbol {

public:
	Symbol();
	Symbol(char newChar);
	Symbol(const Symbol& copy);
	~Symbol();

	char getChar() const;
	int getID() const;
	void setChar(char newChar);

	Symbol& operator= (const Symbol& copy);

	friend std::ostream& operator<< (std::ostream& lhs, const Symbol& rhs);
	friend std::istream& operator>> (std::istream& lhs, Symbol& rhs);
	friend bool operator== (const Symbol& lhs, const Symbol& rhs);
	friend bool operator!= (const Symbol& lhs, const Symbol& rhs);
	friend bool operator< (const Symbol& lhs, const Symbol& rhs);
	friend bool operator> (const Symbol& lhs, const Symbol& rhs);
	friend bool operator<= (const Symbol& lhs, const Symbol& rhs);
	friend bool operator>= (const Symbol& lhs, const Symbol& rhs);

private:
	char character;
};