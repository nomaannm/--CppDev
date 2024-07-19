#include<iostream>
#include<string>
#include<algorithm>

namespace apple
{
	int add(int a, int v)
	{
		return a + v;
	}
}

namespace orange
{
	int add(int b)
	{
		return ++b;
	}
}

int main()
{
	using namespace apple;
	namespace o = orange;
	std::cout << add(2, 3) << std::endl;
	std::cout << o::add(3) << std::endl;

}