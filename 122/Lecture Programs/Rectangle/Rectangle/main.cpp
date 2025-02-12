#include "Rectangle.hpp"

int main() {
	Rectangle r1(4.3, 5);
	//Rectangle r2 = Rectangle(3.0, 2.0);
	//Rectangle r3 = Rectangle();
	Rectangle r4(r1);
	ifstream inputStream;

	double len;

	// no longer "r", now std::ios::in
	inputStream.open("rectangle_data.txt", std::ios::in);

	inputStream >> len;

	cout << len << std::endl;

	cout << "L: " << r1.getLength() << ", W: " << r1.getWidth() << endl;

	//r1.setLength(4.0);
	//r1.setWidth(2.5);

	cout << "L: " << r1.getLength() << ", W: " << r1.getWidth() << endl;

	//cout << r1 << " " << r2 << " " << r3 << std::endl;

	return 0;
}