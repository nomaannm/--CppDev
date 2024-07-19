#include<iostream>
#include<array>

int main() {
	//Second largest in the given array
	int maximum = INT_MIN;
	int second_largest = INT_MIN;
	
	std::array<int, 4> arr = { 10,20,50,30 };
	
	for (int i{ 0 }; i < arr.size(); i++) {
		if (maximum < arr[i]) maximum = arr[i];
	}
	std::cout << maximum << std::endl;

	for (int i{ 0 }; i < arr.size(); i++) {
		if (second_largest < arr[i] && arr[i] != maximum) second_largest = arr[i];
	}

	std::cout << second_largest << std::endl;

}
