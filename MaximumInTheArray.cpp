#include<iostream>
#include<array>

int main() {
	//Max in the Array
	int maximum = INT_MIN;
	std::array<int, 4> arr = { 10,20,50,30 };
	for (int i{ 0 }; i < arr.size(); i++) {
		if (maximum < arr[i]) maximum = arr[i];
	}
	std::cout << maximum << std::endl;
}
