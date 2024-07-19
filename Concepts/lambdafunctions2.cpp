#include<iostream>

int main()
{
	int a{ 1 };
	int b{ 3 };
	int c{ 5 };
	auto lambda = [a,b,c](int value) {
		std::cout << (a + b + c + value) << std::endl;

	};
	lambda(2);
}
