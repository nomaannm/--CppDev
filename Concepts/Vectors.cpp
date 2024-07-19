#include<iostream>
#include<vector>
using namespace std;


int main() {
	vector<int> myVec{ 1,2,4 };
	cout << "Capacity : " << myVec.capacity() << endl;
	myVec.push_back(5);
	myVec.push_back(4);
	cout << "capacity : " << myVec.capacity() << endl;
	myVec.push_back(6);
	myVec.push_back(7);
	cout << "capacity : " << myVec.capacity() << endl;
	myVec.shrink_to_fit();
	cout << "capacity : " << myVec.capacity() << endl;

	//myvec.erase(iterator) like myVec.begin() or myVec.end()
	myVec.erase(myVec.begin());

	for (int i{ 0 }; i < myVec.size(); i++) {
		cout << myVec[i] << endl;
	}

	for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++) {
		cout << *it << endl;

	}

	vector<long> myVec2;
	//reserving the capacity of the vector 
	myVec2.reserve(50);
	for (size_t i = 0; i != 50; i++) {
		/// myVec2.push_back(long;
	}


}
