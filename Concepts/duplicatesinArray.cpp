#include<iostream>
#include<array>
#include<math.h>

int main() {
	//finding duplicates 
	std::array<int, 6> arr = { 2,3,4,2,1,3 };
	bool flag = false;
	for (int i{ 0 }; i < arr.size(); i++) {
		for (int j{ i + 1 }; j < arr.size(); j++) {
			if (arr[i] == arr[j]) {
				flag = true;
				break;
			}
			else continue;
		}
	}

	if (flag) std::cout << "yes" << std::endl;
	else std::cout << "no" << std::endl;


}
