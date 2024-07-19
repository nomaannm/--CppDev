// @mutexes.cpp

#include<iostream>
#include<thread>
#include<ostream>
#include<iterator>
#include<vector>
#include<mutex>

std::mutex Lock;
static int sharedValue = 1;

void shared_increment() {
	Lock.lock();
	sharedValue += 1;
	Lock.unlock();
}


int main()
{
	using namespace std;

	ostream_iterator<string>  oo = cout ;
	ostream_iterator<int> bo = cout;

	vector<thread> threads;

	for (int i = 0; i != 100; i++) {
		threads.push_back(thread(shared_increment));
	}

	for (int i = 0; i != 100; i++) {
		threads[i].join();
	}

	oo = "Shared Value : ";
	oo++;
	bo = sharedValue;




}
