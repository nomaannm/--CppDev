#include<iostream>
#include<limits>

class alignas(16) CustomType {
	int e;
	int c;
};


int main() {
	std::cout << alignof(int) << std::endl;
	std::cout << alignof(int*) << std::endl;
	std::cout << alignof(double) << std::endl;
	std::cout << alignof(double*) << std::endl;
	
	alignas(16) int alignedData;
	std::cout << alignof(int) << std::endl;

	std::cout << alignof(CustomType) << std::endl;


}
