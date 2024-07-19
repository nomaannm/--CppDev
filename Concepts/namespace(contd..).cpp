#include<iostream>

namespace Int {
	int add(int a, int b);

}
int Int::add(int a, int b) {
	return a + b;
}

namespace Float {
	auto add(auto a, auto b) -> float {
		return a + b;
	}
}

namespace American_Telephone_and_Telegraph {
	auto something = 0;
}

namespace ATT = American_Telephone_and_Telegraph;

int main() {
	std::cout << Int::add(2, 3.2) << std::endl;
	std::cout << Float::add(2, 3.2) << std::endl;
	ATT::something;
}
