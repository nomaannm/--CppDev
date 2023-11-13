#include<iostream>
#include<vector>

void print(int a)
{
	std::cout << a << "\n";
}

void iterate(const std::vector<int>& values, void(*func)(int a))
{
	for (int v : values) func(v);
}

int main()
{
	std::vector<int> values = { 1,2,4,5 };
	//using lambda function
	iterate(values, [](int val) {std::cout << val << std::endl; });
}
