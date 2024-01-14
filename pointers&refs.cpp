#include<iostream>
#include<limits>

int function(int x) {
	return x;
}

int main() {
	int* a = new int;
	std::cout << a << std::endl;

	int ac = 7;
	int b = 6;
	int* const ptr = &ac;
	std::cout << ptr << std::endl;
	
	int* volatile pointer = &b;

	int y = 7;
	int& refY = y; // lValue reference
	std::cout << refY << " , " << ++refY << std::endl;

	decltype(function(6)) a = 7;
	std::cout << a << std::endl;

	

}
