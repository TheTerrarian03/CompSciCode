// AO

// This example introduces inheritance. Note that
// the Manager class is derived from the Employee class

#include <iostream>
#include <string>

// Inheritance starter code! Not yet complete!

#include "Employee.hpp"
#include "Manager.hpp"

void printPay(Employee e);

int main(void)
{
	// Employee e1("John", 16.85, 80);
	// Manager m1("Jane", 3500, 75, true);

	Employee *employeeList[10] = {nullptr};
	int numEmployees = 0, option = 0, count=0, type = 0;

	cout << "Enter the number of employees:";
	cin >> numEmployees;

	for (; count < numEmployees; count++) {
		cout << "Employee or manager? 1) hourly employee, 2) manager: ";
		cin >> type;

		switch (type) {
			case 1: employeeList[count] = new Employee("John", 16.85, 80);
					break;
			case 2:	employeeList[count] = new Manager("Jane", 3500, 80, true);
					break;
			
			// employeeList[count]->setHours(80);
		}
		// cout << "Pay: " << employeeList[count]->calculatePay() << endl;
		printPay(*employeeList[count]);
		delete employeeList[count];
	}

	return 0;
}

void printPay(Employee e) {
	cout << e.getName() << ": " << e.calculatePay() << endl;
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
