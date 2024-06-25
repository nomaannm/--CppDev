#include<iostream>

int main() {
	 // References can't be null and must be initialised at declaration.

	int var = 10;
	int& refVar = var;
	refVar ^= var;
	std::cout << refVar << std::endl;

}
