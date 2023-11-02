#include<iostream>
#include<string>

class Base
{
	public:
		virtual std::string getName() { return "Base"; }
};
class Derived : public Base
{
	private:
		std::string mName;
	public :
		Derived(std::string name ) : mName {name } {}
		std::string getName() override {
			return mName;
		}
};

int main()
{
	Base b;
	Derived d("Noman");
	std::cout << b.getName() << std::endl;
	std::cout << d.getName() << std::endl;
}
