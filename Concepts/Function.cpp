#include<iostream>
#include<tuple>
#include<cstdarg>
#include<string>
// F U N C T I O N S 

auto add(int a, auto b) {
	return a + b;
}
void Print(auto arg) {
	std::cout << arg << std::endl;
}
auto mult(auto a, auto b) -> int {
	return a * b;
}

template<typename T,typename S>
auto func(const T a, const S b) -> decltype(a* b) {
	return a * b;
}

//The code is made faster due to this inline function as the compiler susbtitutes the code in place of function call
inline int fac(int n) {
	return (n < 2) ? 1 : n * fac(n - 1);
}

constexpr int  area(int side) {
	return side * side;
}

constexpr int CArea(int radius) {
	const int PI = 3.14;
	if (radius == 0) return 0;
	return PI * radius * radius;
}
[[noreturn]] void Func() {
	std::cout << "[[noreturn]]" << std::endl;
}

/*int sumOfManyNumbers(int num...) {
	std::va_list ap;
	va_start(ap, num);
	int sum = 0;
}*/

/*template<typename T>
[[noreturn]] void funcInitList(std::initializer_list<T> values) {
	for (auto x : values) {
		Print(x);
	}
}*/

//The one with the default args
int addNum(int a, int b = 10) {
	return a + b;
}
int multiply(int a , int b = 10 ) {
	return a * b;

}

//Now demonstration of overloading
void repeat(int a) {
	Print(a + (10 * a));
}

void repeat(std::string str) {
	std::cout << str << str << std::endl;
}

void repeat(std::string str1, std::string str2) {
	std::cout << str1 << str2 << std::endl;
}


// Pointer to Function
void error(std::string s) {
	std::cout << s << std::endl;
}

void (*fnPtr)(std::string s); //Ptr


int main() {
	Print(add(2, 3));
	Print(add(2, 3.4));
	Print(mult(2.3, 3.4));
	Print(fac(6));
	Print(fac(7));
	Print(fac(5));
	constexpr int Area = area(2);
	constexpr int RArea = 2 * 4;
	constexpr int CArea1 = CArea(0);
	constexpr int CArea2 = CArea(2);
	Func();
	int arr[]{ 2,3,4 };
	//funcInitList({ "Nomaan" , "Mumtaz"});
	Print(addNum(2,22));
	Print(addNum(2));
	Print(multiply(2));
	repeat(2);
	repeat("Bee");
	repeat("Bee", "hive");
	fnPtr = &error;
	fnPtr("Function Pointer");
}
