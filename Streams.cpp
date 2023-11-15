#include<iostream>
#include<ostream>
#include<string>

struct Entry {
	std::string name;
	int number;

	Entry(const std::string& name,int num) : name(name), number(num) {}
};
std::ostream& operator<<(std::ostream& os, const Entry& e) {
	return os << "{\"" << e.name << "\", " << e.number << "}";
}


int main()
{
	Entry nomaan("Nomaan", 8615123457);
	Entry talha("Talha", 9992235612);

	std::cout << nomaan << std::endl;
	std::cout << talha << std::endl;
}
