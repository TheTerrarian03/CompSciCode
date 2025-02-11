#include "Complex.hpp"

int main() {
	Complex c1 = Complex(3.5, 2);
	Complex c2 = Complex(5.5, 7);
	Complex c3;

	// part a done
	c3 = c1.add(c2);
	c3 = add(c1, c2);
	c3 = c1 + c2;

	std::cout << "a) c3: " << c3.getA() << " + " << c3.getB() << "i" << std::endl;

	// part b
	c3 = c1 - c2;

	std::cout << "b) c3: " << c3.getA() << " + " << c3.getB() << "i" << std::endl;

	// part c
	std::cout << "Please enter your imaginary number in the form `a + bi`" << std::endl << "> ";
	Complex c4;
	c4.read();
	
	std::cout << "Please enter another imaginary number and another:" << std::endl << "> ";
	Complex c5;
	Complex c6;
	std::cin >> c5 >> c6;

	c5.print();
	std::cout << c6;

	
} 