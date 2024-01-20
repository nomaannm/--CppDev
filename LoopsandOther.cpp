#include<iostream>
#include<vector>

int main() {
	enum Color {
		red ,green,blue
	};

	int color = Color::red;

	switch (color) {
		case Color::red :
			std::cout << "Red" << std::endl;
			++color;
			break;
		case Color::blue:
			std::cout << "Blue" << std::endl;
			++color;
			break;
		case Color::green:
			std::cout << "Green" << std::endl;
			++color;
			break;
	}

	{
		std::vector<int> v = { 1,2,3,4 };

		for (auto p = begin(v); p != end(v); p++) {
			std::cout << *p << std::endl;
		}
		int i = 0;
		for (;i *i <= 4096;) {
			std::cout << i;
			i++;
		}

	label: std::cout << 4 * 2 << std::endl;
		for (int i = 0; i < 10; i++) {
			if (i % 2 == 0) goto label;
			std::cout << 5 * 2 << std::endl;
	}


	}

}
