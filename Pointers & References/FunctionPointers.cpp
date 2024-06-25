#include<iostream>

void print(std::string a, std::string b){
	std::cout << "The two strings are : " << a << " & " << b << std::endl;
}

int main() {
	// Function Pointer
	void (*funcptr)(std::string, std::string) = print;

	funcptr("Hello", "World");

}
