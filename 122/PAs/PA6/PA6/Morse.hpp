/*
- File: Morse.hpp
- Description: Function declerations and variables for the Morse class
- Morse class: This class holds a simple string of characters representing a
			   sequence of dots and dashes (not enforced)

- Added: 03/23/2025
*/

#pragma once

#include <iostream>

class Morse {

public:
	Morse();
	Morse(const std::string seq);
	Morse(const Morse& copy);
	
	std::string getSequence() const;
	void setSequence(std::string newSequence);

	Morse& operator= (const Morse& copy);
	friend std::ostream& operator<< (std::ostream& lhs, const Morse& rhs);
	friend std::istream& operator>> (std::istream& lhs, Morse& rhs);

private:
	std::string sequence;
};