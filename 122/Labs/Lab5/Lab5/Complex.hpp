#pragma once

#include <iostream>
#include <istream>
#include <ostream>

class Complex {

private:
	double a;
	double b;

public:
	// Constructors
	Complex();
	Complex(double, double);

	// Setters
	void setA(double);
	void setB(double);

	// Getters
	double getA() const;
	double getB() const;

	// Methods
	Complex& add(const Complex&); 
	void read();
	void print();

};

// operator functions ish
Complex add(const Complex&, const Complex&);

// operator overloads
Complex operator+ (const Complex&, const Complex&);

Complex operator- (const Complex&, const Complex&);

std::istream& operator>> (std::istream&, Complex&);

std::ostream& operator<< (std::ostream&, const Complex&);