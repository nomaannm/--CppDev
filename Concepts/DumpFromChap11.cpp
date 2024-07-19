/* 
* @author Noman Mumtaz
* These are soe conditional operations anr bitwise operations from Chapter 11
*/

#include<iostream>
using namespace std;

constexpr unsigned short middle(int a) {
	static_assert(sizeof(int) == 4 , "Unexpected Int Size");
	static_assert(sizeof(short) == 2, "Unexpected Short Size");
	return (a >> 8) & 0xFFF;
}

void check(int* p) {
	int y = (p) ? *p : throw std::runtime_error{"unexpected nullptr "};
    std::cout << y << std::endl;
}


int main() {
	using namespace std;
	int x = 0xff00ff00;
	short y = middle(x);
	cout << y << endl;

	int a = 10;
	int* aPtr = &a;
	check(aPtr);
	// int* bPtr = nullptr;
	// check(bPtr);
}
