#include <iostream>

class foo {
public:
	virtual void func() {
		std::cout << "inside class foo" << std::endl;
	}
};

class bar : public foo {
public:
	void func() override {
		std::cout << "Inside class bar" << std::endl;
	}
};

int main() {

	foo f = foo();
	foo* f_ptr = new foo();

	bar b = bar();
	bar* b_ptr = new bar();

	foo* fb_ptr = new bar();

	f.func();
	f_ptr->func();

	b.func();
	b_ptr->func();

	fb_ptr->func();

	return 0;
}