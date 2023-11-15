#include<iostream>
//C++ 11 standard array
#include<array>

int main() {
	//This is created on the stack. Once the program execution reaches the end curly brace , this array would destroy. 
	int arr[5];
	int* ptr = arr;

	arr[0] = 2;
	std::cout << arr[0] << std::endl;
	*(ptr + 2) = 2;
	std::cout << arr[0] << " & " << arr[2] << std::endl;
	*(int*)((char*)ptr + 8) = 6;
	std::cout << arr[0] << " & " << arr[2] << std::endl;


	//This is created on heap. This has to be destroyed using the delete keyword.
	int* another = new int[5];

	delete[] another;

	std::array<int, 5> Array;
	for (int i{ 0 }; i < Array.size(); i++) {
		Array[i] = i;
	}
	for (int i{ 0 }; i < Array.size(); i++) {
		std::cout << Array[i] << std::endl;
	}


}
