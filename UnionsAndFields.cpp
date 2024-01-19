#include<iostream>

struct Date {
	unsigned int d;
	unsigned int m;
	unsigned int y;
};

struct DateBF {
	unsigned int d : 5;
	unsigned int m : 4;
	unsigned int y;
};

union Union{
	const char* name = "";
	double d;
	int age;

};
class Entry {
	public :
		union {
			int m;
			float n;
		};

};




int main() {
	std::cout << sizeof(Date) << std::endl << sizeof(DateBF) << std::endl << sizeof(Union) << std::endl;
	Union u;
	u.age = 2;
	std::cout << u.age << "," << u.d << "," << u.name << std::endl;
	u.name = "String";
	std::cout << u.age << "," << u.d << "," << u.name << std::endl;
	Entry obj;
	obj.m = 10;
}
