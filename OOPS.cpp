#include<iostream>


class IEntity {
	// By making it a pure virtual function, we are making it obligatory to implement it in all classes.
	virtual void AskForPromotion() = 0 ;
};

class Entity : IEntity{
	/* Attributes and behaviours are to be defined here */
	private:
		std::string Name;
		std::string companyName;
		int age;
	protected:
		std::string toBeProtected;
	public:
		Entity(std::string n, std::string cn, int age) :Name{ n }, companyName{ cn }, age{ age } {}

		void AskForPromotion(){
			std::cout << "We signed the contract. " << std::endl;

		}

		virtual void Work() {
			std::cout << Name << " is working." << std::endl;
		}

		// GETTERS AND SETTERS
		void setName(std::string name) {
			this->Name = name;
		}

		std::string getName() {
			return this->Name;
		}

		static std::string getName(Entity e) {
			return e.Name;
		}

};

class Developer : public Entity {
	public : 
		std::string favprogrammingLang;
		Developer(std::string name, std::string companyName, int age, std::string fvCodingLang) : Entity(name, companyName, age) {
			favprogrammingLang = fvCodingLang;
		}

		decltype(toBeProtected) protectedInParent = toBeProtected;

		void fixBug() {
			std::cout << getName() << " fixed bug using " << favprogrammingLang << std::endl;
		}

		void Work() {
			std::cout << getName() << " is coding..." << std::endl;
		}


};

int main() {
	Entity entity = { "Nomaan" , "LinkedIn" , 22 };
	Developer dev = Developer("Arhan", "Amazon", 22, "C++");
	dev.fixBug();
	entity.Work();
	dev.Work();
}
