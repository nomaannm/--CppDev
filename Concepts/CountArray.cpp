#include<iostream>
#include<array>

int main() {
	//Counting numbers greater than x
	int target;
	std::cin >> target;

	int count = 0;
	std::array<int, 10> arr = { 2,34,1,5,6,7,3,9,12,98 };
	for (auto x : arr) {
		if (x > target) count++;

	}
	std::cout << "Count : " << count << std::endl;

}
