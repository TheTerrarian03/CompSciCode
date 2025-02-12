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