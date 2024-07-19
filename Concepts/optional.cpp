#include<iostream>
#include<optional>
#include<fstream>

std::optional<std::string> fileReader(const std::string filepath, bool& success) {

	std::ifstream stream(filepath);

	if (stream) {
		std::string result;
		stream.close();
		return result;

	}
	else {
		return {};
	}
}

int main() {
	std::optional<std::string> ReadString("Data.txt");
	if (ReadString.has_value()) {
		std::cout << "File read successfully !" << std::endl;
	}
	else std::cout << "File has no data ! " << std::endl;
}
