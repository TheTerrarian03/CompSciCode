#include "Rectangle.hpp"

Rectangle::Rectangle() {
	mLength = mWidth = 0.0;
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