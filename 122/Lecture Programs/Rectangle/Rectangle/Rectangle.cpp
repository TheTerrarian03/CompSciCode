#include "Rectangle.hpp"

//Rectangle::Rectangle() {
//	mLength = mWidth = 0.0;
//}

Rectangle::Rectangle(double len, double wid) {
	if (len >= 0) mLength = len;
	else mLength = 0;

	if (wid >= 0) mWidth = wid;
	else mWidth = 0;
}

// copy constructor - define how an object of Rectangle type is should be copied
// scenario: passed by value (PASS BY REFERENCE IN PARAMETERS)
Rectangle::Rectangle(Rectangle& r) {
	mLength = r.mLength;
	mWidth = r.mWidth;
}

// copy assignment operator
Rectangle& Rectangle::operator=(Rectangle& rhs) {
	// self-referential assignment
	if (this != &rhs) {
		mLength = rhs.mLength;
		mWidth = rhs.mWidth;

		// "this" is a pointer to an instance of an object
		//cout << "Address of this: " << this << endl;
	}

	return *this;
}

// desstruction
Rectangle::~Rectangle() {
	// clean up resources
	cout << "Inside Rectangle Destructor: " << *this << endl;
}

// getters - accessorororororewhiosghbdfjkcghewnigsrkxjgnoeguiwrbksjdy7593t408p2iwesdkljbfkdjlkivpgru5yrgej
double Rectangle::getLength() {
	return mLength;
}
double Rectangle::getWidth() {
	return mWidth;
}

// setters - mutatorheuothrgulegbrljgrdlgreutohlwi4rsgkjfx
void Rectangle::setLength(double newLength) {
	// validate data
	if (newLength >= 0) {
		mLength = newLength;
	}
}
void Rectangle::setWidth(double newWidth) {
	if (newWidth >= 0) {
		mWidth = newWidth;
	}
}

std::ostream& operator<< (std::ostream& lhs, Rectangle& rhs) {
	lhs << "l: " << rhs.getLength() << " w: " << rhs.getWidth();
	return lhs;
}


// overloaded operator - non-member
ifstream& operator>> (ifstream& lhs, Rectangle& rhs) {
	double len, wid;

	lhs >> len >> wid;

	rhs.setLength(len);
	rhs.setWidth(wid);

	return lhs;
}