#include<iostream>

enum class Color  {
	red , green , blue 
};

enum PlainColor {
	red , green , blue 
};

enum class IntColor : int {
	red , green , blue 
};

enum class CharColor : char {
	red , green , blue 
};

enum trigger  {
	entry = 0, mid, end
};

enum trigger2 {
	entry = 0 , middle = 2 , end = 4
};


int main() {
	// int n = Color::red;
	int n = PlainColor::red;
	Color obj = Color::red;

	std::cout << sizeof(IntColor) << std::endl << sizeof(CharColor) << std::endl;

}
