#include<iostream>

class Cylinder {
	int radius;
	float height;
	const double PI = 3.14;

public:
	void setRadiusAndHeight(int r , auto h) {
		radius = r;
		height = h;
	}

	friend void calculateResults(Cylinder);
	friend class Homework;
};

void calculateResults(Cylinder c) {
	std::cout << "LSA : " << 2 * c.PI * c.radius * c.height << "\n";
	std::cout << "TSA : " << 2 * c.PI * c.radius * (c.height + c.radius) << "\n";
}

class Homework {
	public:
		void calculateResults(Cylinder c) {
			std::cout << "LSA : " << 2 * c.PI * c.radius * c.height << "\n";
			std::cout << "TSA : " << 2 * c.PI * c.radius * (c.height + c.radius) << "\n";
			std::cout << "Volume : " << c.PI * c.radius * c.radius * c.height << "\n";

		}

};



int main() {
	Cylinder c;
	c.setRadiusAndHeight(2, 10.8);
	calculateResults(c);
	Homework homework;
	homework.calculateResults(c);


}
