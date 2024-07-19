#include<iostream>
#include<string>

struct {
	const char* name;
	int age;
} s1 , s2;

struct Person {
	std::string  name;
	float salary;
};

struct Readout1 {
	char hour;
	int value;
	char seq;

};

struct Readout2 {
	int value;
	char hour;
	char seq;
};

struct Readout3 {
	char seq;
	char hour;
	int value;
};

int Readout3() {
	std::cout << "Hello World";
	return 1;
}


int main() {
	s1.age = 20;
	s1.name = "Kaif";
	std::cout << s1.age << std::endl <<  s1.name << std::endl;

	Person p = { "Zain" , 20000 };
	std::cout << p.name << std::endl << p.salary << std::endl;

	Readout1  rd1;
	Readout2 rd2;
	Readout3 rd3;
	std::cout << "Size of Readout1 : " << sizeof(rd1) << std::endl << "Size of Readout2 : " << sizeof(rd2) << std::endl <<
		"Size of Readout3 : " << sizeof(rd3) << std::endl;


}
