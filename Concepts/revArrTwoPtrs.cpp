#include<iostream>
#include<array>
#include<math.h>

int main() {
	//TWO POINTERS
	//reversing the array without extra array
	std::array<int, 6> arr = { 2,3,4,2,1,3 };
	for (int i{ 0 }, j{ arr.size() - 1 }; i < j; i++, j--) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << std::endl;
	}

	


}
