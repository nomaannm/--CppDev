#include<iostream>

bool check(int a, int b) {
	bool Bool{ a == b };
	return Bool;
}
int main() {
	std::cout << check(3, 4) << std::endl << check(6, 6) << std::endl;
	std::cout << check(4, 4) + 1 << std::endl;


	int a = 2, b = 1, c = 0, d = 0;
	bool b1 = a + b;
	bool b2 = b || c;
	bool b3 = c && d;
	std::cout << b1 << ", " << b2 << ", " << b3;

 
}
