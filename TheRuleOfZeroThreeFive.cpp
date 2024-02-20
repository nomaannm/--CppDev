// THE RULE OF ZERO, THREE, FIVE
#include<iostream>

class Source {
public:
	int a = 0;
	Source(int value) : a{value} {}
};

int main() {
	// This is the rule of zero...
	// Dont define copy constructor, copy assignment operator, constructor if not needed.
	Source source1 = Source(2);
	std::cout << source1.a << std::endl;
	Source source2 = Source(source1);
	std::cout << source2.a << std::endl;

	// till here

	// This is the rule of five...
	// The Rule of Five extends the Rule of Three to include two additional special member functions:
    // Move constructor
	// Move assignment operator

	// This is the rule of three...
	// The Rule of Three states that a class or structure that manages resources should define the following three special member functions:
    // Destructor
	// Copy constructor
    // Copy assignment operator


	 
}
