// @structured_bindings.cpp

#include<iostream>
#include<tuple>
#include<string>
#include<ostream>

//We can add more objects in the tuple
std::tuple<std::string, int> createPerson() noexcept {
	return { "Noman",21 };
}

// but a pair can only contain two heterogeneous objects
std::pair<int , std::string> createPerson(auto blahblahblah) noexcept {
	return { "Nomaan" , 21 };
}


int main() {
	auto person = createPerson();
	std::string& name = std::get<0>(person);
	int age = std::get<1>(person);
	std::cout << name << age << std::endl;

	std::tie(name, age) = createPerson();
	std::cout << name << " " << age << std::endl;

	auto [names, ages] = createPerson();
	std::cout << names << ages << std::endl;

}
