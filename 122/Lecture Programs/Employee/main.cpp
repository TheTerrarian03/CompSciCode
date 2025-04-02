// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

#include <iostream>
#include <string>

// Inheritance starter code! Not yet complete!

#include "Employee.hpp"
#include "Manager.hpp"

int main(void)
{
	Employee mEmployees[5];

	switch (type) {
		case 1:
			mEmployees[count] = new Employee()
	}

	return 0;
}

// constructors, descructors, friends, and the oeverloaded assignment operator is not inherited
// you could use `friend class List` to give List access to inner Node functions

// single inheritance:
	// class Manager : public Employee

// multiple inheritance:
	// be aware of the base cases involved, and what might be be conflicting
	// class TeachingAssistant : public Worker, public Student

// multilevel inheritance:
	// class Officer : Manager // indirect `: Employee` here

// heirchical Inheritance:
	// multiple classes inheriting from one
	// from top going down, going futher down there will be more specialization/power/responsibility
	// class CEO : public Officer
	// class COO : public Officer

// Hybrid Inheritance:
	// a mix of the other forms
	// class Chairman : public CEO, public COO
	// diamond problem
