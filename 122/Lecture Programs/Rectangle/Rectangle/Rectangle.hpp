#pragma once

#include <iostream>  // input output operations; cout cin
#include <fstream>  // for file reading/writing

// using namespace std;  // don't do
using std::cin;  // cin >> str instead of std::cin
using std::cout;
using std::endl;
using std::ifstream;  // input file stream

struct rect {
	double mLength;
	double mWidth;
};

class Rectangle {
public:
	// member functions - methods
	// constructor - default constructor - special member function
	//Rectangle();
	// constructor w/ parameters
	//Rectangle(double, double);
	// constuctor w/ default arguments
	Rectangle(double len = 0, double wid = 0);

	// Rule of three:
	// copy constructor - define how an object of Rectangle type is should be copied
	// scenario: passed by value (PASS BY REFERENCE IN PARAMETERS)
	Rectangle(Rectangle &r);

	// copy assignment operator

	// desructor


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