#include<iostream>
#include<algorithm>
#include<vector>

struct Goblin
{
	int mHealth;
	int mStrength;
	Goblin(int h, int s) : mHealth{ h }, mStrength{ s } {

	}
	bool operator<(const Goblin& rhs)
	{
		return this->mHealth < rhs.mHealth;
	}
};

//Now we're creating a FUNCTOR to sort this on the strength
struct Comparator {
	//to create a Functor we have to overload parantheses
	bool operator()(const Goblin& lhs, const Goblin& rhs) const 
	{
		return lhs.mStrength < rhs.mStrength;

	}
};

int main()
{
	std::vector<Goblin> goblins{ Goblin(3,2) , Goblin(2,5),Goblin(10,1) };
	std::sort(begin(goblins), end(goblins),Comparator());
	for (auto g : goblins)
		std::cout << g.mHealth << "\n";
}
