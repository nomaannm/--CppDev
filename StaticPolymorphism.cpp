#include<iostream>

class ALIEN {
		private :
			std::string name;
		public:
			ALIEN(std::string n) : name{ n } {

			}
			void brief(int age) {
				std::cout << "I am an ALIEN and my age is " << age << std::endl;
			
			}
			void brief(const char* something) {
				std::cout << "I am an ALIEN and " << something << "\n";
			}
			int brief(double age) {
				std::cout << "I am an ALIEN and my age is  " << age << "\n";
				return age;
			}

			template<typename T, typename C>
			T introduce(C age, std::string name) {
				std::cout << "I am an ALIEN , my name is " << name << " and my age is " << T(age) << std::endl;
				return age;
			}

};


int main() {
	ALIEN alien = ALIEN("EVANS");
	alien.brief(2);
	alien.brief("vhgfebkjbe");
	alien.brief(2.3);
	alien.introduce<double, int>(2.3, "EVANS");
}
