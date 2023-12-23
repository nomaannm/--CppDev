#include<iostream>
#include<variant>

struct Person {
	std::string firstName;
	std::string lastName;
};

enum class ErrorCode {
	None = 0, NotFound, NoAccess
};

std::variant<int, double, ErrorCode> Returns(std::variant<int,double,ErrorCode> deduce) {
	if (typeid(deduce).name() == int) return int(deduce);
	if (typeid(deduce).name() == double) return std::get<double>(deduce);
	else return std::get<ErrorCode>(deduce);
}



int main() {
	std::variant<std::string, int, float, double, Person> data;
	data = "Nomaan";
	std::cout << "String : " << std::get<std::string>(data) << std::endl;
	data = 2;
	std::cout << "Integer : " << std::get<int>(data) << std::endl;
	data = 3.4f;
	std::cout << "Float : " << std::get<float>(data) << std::endl;
	data = 3.008;
	std::cout << "Double : " << std::get<double>(data) << std::endl;
	std::cout << Returns(1) << std::endl;

}
