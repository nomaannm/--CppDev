#include<iostream>
#include<array>
#include<math.h>

int main() {
	//reverse order 
	std::array<int, 6> arr = { 2,3,4,2,1,3 };
	std::array<int, arr.size()> reverse_arr;
	int j = 0;
	for (int i = arr.size() - 1; i > -1; i--) {
		reverse_arr[j] = arr[i];
		j++;
	}

	for (int i = 0; i < reverse_arr.size(); i++) {
	   std::cout << reverse_arr[i] << std::endl;
	}

	


}
