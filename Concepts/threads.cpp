#include<iostream>
#include<thread>

static bool isFinished = false;


void doWork() {

	using namespace std::literals::chrono_literals;

	std::cout << "Started thread with id = " << std::this_thread::get_id << std::endl ;

	while (!isFinished)
	{
		std::cout << "Working!!\n";
		std::this_thread::sleep_for(10s);
	}
}

int main() {
	std::thread worker(doWork);

	std::cin.get();

	isFinished = true;


	worker.join(); // wait for the thread to exit 

	std::cin.get();

}
