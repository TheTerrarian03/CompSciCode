#include "Complex.hpp"

// constructors
Complex::Complex() {
	setA(0.0);
	setB(0.0);
}
Complex::Complex(double _argA, double _argB) {
	setA(_argA);
	setB(_argB);
}

// setters
void Complex::setA(double _arg) {
	a = _arg;
}
void Complex::setB(double _arg) {
	b = _arg;
}

// getters
double Complex::getA() const {
	return a;
}
double Complex::getB() const {
	return b;
}

// member methods
Complex& Complex::add(const Complex& rhs) {
	a += rhs.a;
	b += rhs.b;
	return *this;
}

void Complex::read() {
	char sign, i;

	std::cin >> a >> sign >> b >> i;

	if (sign == '-') b *= -1;

	//std::cout << "Got nums: " << a << " + " << b << i << std::endl;
}

void Complex::print() {
	double pos_b;
	char sign;

	if (b >= 0) {
		pos_b = b;
		sign = '+';
	}
	else {
		pos_b = -b;
		sign = '-';
	}

	std::cout << a << " " << sign << " " << pos_b << "i" << std::endl;
}

// non-member functions
Complex add(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs.getA() + rhs.getA(), lhs.getB() + rhs.getB());
}

Complex subtract(const Complex& lhs, const Complex& rhs) {
	return Complex(lhs.getA() - rhs.getA(), lhs.getB() - rhs.getB());
}

Complex operator+ (const Complex& lhs, const Complex& rhs) {
	return add(lhs, rhs);
}

Complex operator- (const Complex& lhs, const Complex& rhs) {
	return subtract(lhs, rhs);
}

std::istream& operator>> (std::istream& lhs, Complex& rhs) {
	double a, b;
	char sign, i;

	lhs >> a >> sign >> b >> i;

	if (sign == '-') b *= -1;

	rhs.setA(a);
	rhs.setB(b);

	//std::cout << "Got nums: " << rhs.getA() << " + " << rhs.getB() << i << std::endl;

	return lhs;
}

std::ostream& operator<< (std::ostream& lhs, const Complex& rhs) {
	double pos_b;
	char sign;

	if (rhs.getB() >= 0) {
		pos_b = rhs.getB();
		sign = '+';
	}
	else {
		pos_b = -rhs.getB();
		sign = '-';
	}
	
	lhs << rhs.getA() << " " << sign << " " << pos_b << "i";

	return lhs;
}