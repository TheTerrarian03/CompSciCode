#include "Rectangle.hpp"

int main() {
	Rectangle r1(4.3, 5);
	Rectangle r2;
	Rectangle r3;
	Rectangle r4(r1);
	r2 = r1;
	cout << "Address of r1: " << &r3 << endl;
	ifstream inputStream;

	double len = 0, wid = 0;

	// no longer "r", now std::ios::in
	inputStream.open("rectangle_data.txt", std::ios::in);

	inputStream >> len >> wid;

	r3.setLength(len);
	r3.setWidth(wid);

	cout << r3 << endl;

	inputStream >> r3;

	cout << r3 << endl;

	inputStream.close();

	//cout << len << std::endl;

	cout << "L: " << r1.getLength() << ", W: " << r1.getWidth() << endl;

	//r1.setLength(4.0);
	//r1.setWidth(2.5);

	cout << "L: " << r1.getLength() << ", W: " << r1.getWidth() << endl;

	//cout << r1 << " " << r2 << " " << r3 << std::endl;

	return 0;
}