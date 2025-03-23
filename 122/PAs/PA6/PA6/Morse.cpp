/*
- File: Morse.cpp
- Description: Function definitions for Morse.hpp

- Added: 03/23/2025
*/

#pragma once

#include "Morse.hpp"

Morse::Morse() : sequence("") {}
Morse::Morse(const std::string seq) : sequence(seq) {}
Morse::Morse(const Morse& copy) { sequence = copy.sequence; }

std::string Morse::getSequence() const { return sequence; }
void Morse::setSequence(std::string newSequence) { sequence = newSequence; }

Morse& Morse::operator= (const Morse& copy) {
	sequence = copy.sequence;
	return *this;
}

std::string sequence;

std::ostream& operator<< (std::ostream& lhs, const Morse& rhs) {
	lhs << rhs.getSequence();
	return lhs;
}

std::istream& operator>> (std::istream& lhs, Morse& rhs) {
	std::string newSeq;

	lhs >> newSeq;

	rhs.setSequence(newSeq);

	return lhs;
}
