#include<iostream>
#include<memory>
#include<chrono>

class Timer {
	public:
		Timer() {
			mstartPoint = std::chrono::high_resolution_clock::now();
		}
		~Timer() {
			// RAII ~ Resource Acquisition is Initialisation
			stop();
		}

		void stop() {
			//for making it scope based , it is called in the destructor
			auto mendPoint = std::chrono::high_resolution_clock::now();

			auto start = std::chrono::time_point_cast<std::chrono::microseconds>(mstartPoint).time_since_epoch();
			auto stop = std::chrono::time_point_cast<std::chrono::microseconds>(mendPoint).time_since_epoch();

			auto duration = stop - start;
			double ms = duration.count() * 0.001;

			std::cout << duration << "us (" << ms << "ms)\n";


		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> mstartPoint;


};

int main() {
	int value = 0;
	for (int i{ 0 }; i < 100000; i++)
		value += 2;

	std::cout << value << std::endl;

	__debugbreak();
}
