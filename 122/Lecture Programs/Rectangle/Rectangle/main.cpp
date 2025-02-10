#include "Rectangle.hpp"

int main() {
	Rectangle r1;

	cout << "L: " << r1.getLength() << ", W: " << r1.getWidth() << endl;

	r1.setLength(4.0);
	r1.setWidth(2.5);

	cout << "L: " << r1.getLength() << ", W: " << r1.getWidth() << endl;

	return 0;
}