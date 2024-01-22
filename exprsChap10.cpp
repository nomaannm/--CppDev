/**
* These code snippets are from Chapter 10 : Expressions from C++ book by Bjarne Stroustrup
*/

#include<iostream>

char f(double d) {
	char  c = d;
	return c;
}

int main(int argc, char* argv[]) {
	int a = 10;
	std::cout << typeid(a).name() << std::endl << typeid(a).raw_name() << std::endl;
	int y;
	int x = y = a;

	// int b = (i = 2, i + 1);
	// std::cout << b << std::endl;
	// if (3 == b) std::cout << b << std::endl;

	std::cout << f(8.3) << std::endl;
	int i(2.7);
	std::cout << i << std::endl;
	int j = float(124454768388);
	std::cout << j << std::endl;
 }
