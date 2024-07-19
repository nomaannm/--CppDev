// THE DIAMOND PROBLEM
// MULTIPLE INHERITANCE

#include<iostream>

class SuperClass {
public:
	SuperClass() {
		std::cout << "SuperClass constructor " << "\n";
	}
};

class Base1 : virtual public SuperClass {
public:
	Base1() {
		std::cout << "Base1 constructor " << "\n";
	}
};

class Base2 : virtual public SuperClass {
public:
	Base2() {
		std::cout << "Base2 constructor" << "\n";
	}
};

class Derived : public Base1, public Base2 {
public:
	Derived() {
		std::cout << "Derived constructor" << "\n";
	}
};

int main() {
	Derived d;
}
