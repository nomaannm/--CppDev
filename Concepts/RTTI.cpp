#include<iostream>
#include<typeinfo>
#include<any>

class Entity {
public:
	virtual void Printname(){}
};

class Player : public Entity {
};

class Enemy : public Entity {
};

int main() {

start: {std::cout << "Enter the data : ";
	auto a = std::cin.get();
	std::cout << typeid(a).name() << std::endl;
	// goto start;
	}

	decltype(3 * 4.4) b;
	const std::type_info& typB = typeid(b);
	std::cout << typB.name() << std::endl;

	Player* player = new Player();
	Entity* actuallyPlayer = player;
	Entity* actuallyEnemy = new Enemy();
	
	Player* p = dynamic_cast<Player*>(actuallyEnemy);
}
