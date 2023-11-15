#include<iostream>
#include<array>

int main() {
	std::array<int, 100> arr;
	int i;
	for (i = 0; i < 98; i++);
	{
		arr[i] = i;
		std::cout << arr[i] << std::endl;
	}


}
