#include<iostream>
#include<memory>

class Entity {
	public:
		Entity() {
			std::cout << "Entity created ! " << std::endl;

		}

		~Entity() {
			std::cout << "Entity deleted ! " << std::endl;
		}
		
		void print() {
		}

};

int main() {
	{
		std::unique_ptr<Entity> entity(new Entity());

		//this one doesn't throws exception
		std::unique_ptr<Entity> entityy = std::make_unique<Entity>();

		entity->print();

		//shared ptrs can be copied !
		///also when shared_ptr is copied to another shared_ptr , reference count is increased !
		std::shared_ptr<Entity> entits = std::make_shared<Entity>();
		std::shared_ptr<Entity> sharedEntits = entits;


		//copying a shared_ptr to a weak_ptr won't increase the ref. count !
		std::weak_ptr<Entity> weakEntity;
	}

	std::cin.get();
}
