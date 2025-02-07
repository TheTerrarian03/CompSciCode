#include <iostream>
#include <string>

// function overloading
int add(int n1, int n2);
std::string add(std::string s1, std::string s2);


int main() {
	std::cout << "Result of int add: " << add(5, 6) << std::endl;
	std::cout << "Result of std::string add: " << add("Hello ", "World!") << std::endl;


	int num = 50;
	int &refNum = num;  // reference operator
	// we have created an alias for an existing variable/object
	num = 75;

	std::cout << "Ref num contents: " << refNum << std::endl;
	std::cout << "Address of num: " << &num << " Address of refNum: " << &refNum << std::endl;

	std::cout << "Hello world!" << std::endl;

	std::string str = "";
	std::cout << "Enter a C++ standard string: ";
	std::cin >> str;
	
	std::cout << "You entered: \"" << str << "\"." << std::endl;

	return 0;
}

int add(int n1, int n2) {
	return n1 + n2;
}
std::string add(std::string s1, std::string s2) {
	return s1 + s2;
}