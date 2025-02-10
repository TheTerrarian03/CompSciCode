#pragma once

#include <iostream>  // input output operations; cout cin
// using namespace std;  // don't do
using std::cin;  // cin >> str instead of std::cin
using std::cout;
using std::endl;

struct rect {
	double mLength;
	double mWidth;
};

class Rectangle {
public:
	// member functions - methods
	// constructor - default constructor - special member function
	Rectangle();

	// getters - accessorororororewhiosghbdfjkcghewnigsrkxjgnoeguiwrbksjdy7593t408p2iwesdkljbfkdjlkivpgru5yrgej
	double getLength();
	double getWidth();

	// setters - mutatorheuothrgulegbrljgrdlgreutohlwi4rsgkjfx
	void setLength(double newLength);
	void setWidth(double newWidth);

private:
	// data members
	double mLength,
		   mWidth;
};

// overloaded operator - non-member
std::ostream& operator<< (std::ostream& lhs, Rectangle& rhs);