// This example illustrates how to define a Stack class template.

#include "Postfix.hpp"

//#include <vector>

int main(void)
{
	/* ------------ 0 ---------- */
	// a. array
	// b. linked
	// c. linked
	// d. array
	// e. linked
	// f. linked
	// g. array

	/* ---------- 2 tests ---------- */

	Stack<char> s;

	std::cout << s.isEmpty() << std::endl;

	char c = 'a';

	s.push(c);

	std::cout << s.isEmpty() << std::endl;

	char b, a;

	s.peek(b);

	std::cout << "Got: " << b << std::endl;

	s.pop(a);

	std::cout << "Got: " << a << std::endl;

	std::cout << s.isEmpty() << std::endl;

	s.push(c);
	c = 'b';
	s.push(c);
	c = 'z';
	s.push(c);

	s.pop(c);

	cout << "got: " << c << endl;

	s.pop(c);

	cout << "got: " << c << endl;

	s.pop(c);

	cout << "got: " << c << endl;

	// s.pop(c);

	// cout << "got: " << c << endl;

	/* ---------- 3 ---------- */

	std::string expr = "4 9 * 3 / 8 + =";
	cout << expr << endl << Postfix::solve(expr) << endl;

	/* ---------- 4 ---------- */

	

	/* ---------- leftover starter code ---------- */

	//	vector<int> my_vector; // vector<> is from the Standard Template Library (STL)

	// TestStack<int> tester;

	// tester.Test(item1, item2);

	return 0;
}
