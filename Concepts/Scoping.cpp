#include<iostream>

int x = 0;

static void funcScope() noexcept {
	int x = 0;
	::x = 2; //changed value of Global X using scope resolution operator
	x = 3;
	std::cout << "Global X : " << ::x << std::endl;
	std::cout << "Local X : " << x << std::endl;

}

int main() {
	funcScope();
}
