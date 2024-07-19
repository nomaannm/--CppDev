#include<iostream>


int main() {
	int a = 7;
	decltype(a) b;

	decltype(3.14 * 2 * 2) var;
	var = 6.28;
	std::cout << var << std::endl;
	var = 6;
	std::cout << var << std::endl;
}
