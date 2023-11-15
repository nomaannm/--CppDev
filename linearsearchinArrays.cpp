#include<iostream>
#include<array>

int main() {
	//Linear Search 
	std::array<int, 5> Array = { 1,10,9,3,4 };
	int target;
	std::cout << "Enter target :";
	std::cin >> target;
	bool flag = false;

	for (int i{ 0 }; i < Array.size(); i++) {
		if (Array[i] == target) {
			flag = true;
			break;
		}
		else continue;

	}

	if (flag) std::cout << target << " is present." << std::endl;
	else std::cout << target << " is absent." << std::endl;

}
