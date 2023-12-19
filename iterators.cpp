#include<iostream>
#include<ostream>

int main() {
	std::ostream_iterator<std::string> oo{ std::cout };
	*oo = "Hello";
	oo++;
	*oo = " World";

}
