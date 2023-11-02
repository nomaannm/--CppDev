#include<iostream>
using namespace std;


int main()
{
	static_assert(sizeof(int) > 4, "The integers are greater than 4.");
}
