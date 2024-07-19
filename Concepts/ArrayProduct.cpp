#include<iostream>
#include<array>

int main() {
	std::array<int, 5> Array = { 1,2,7,6,2 };
	int product = 1;

	for (int i{ 0 }; i < Array.size(); i++) {
		product *= Array[i];
	}

	std::cout << "Product : " << product << std::endl;
}
