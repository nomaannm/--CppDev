int main() {
	int var = 1;
	int& refVar = var;

	//int& refVarX = 2;

	int varY = 2;
	const int& refVarY = 2;
	const int& refVarY2 = varY;
	const char*&& ref{ Func() }; //rvalue ref
	std::cout << ref << std::endl;



}
