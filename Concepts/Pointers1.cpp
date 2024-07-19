#include<iostream>
using namespace std;

int (*func)(char*); //function pointer pointing to some function returning an int

int somefunc(char* c) {
	return 0;
}

int main() {
	func = somefunc;
	std::cout << func << endl;
	char c = 'c';
	char* pTc = &c;
	cout << pTc << endl;
	cout << *pTc << endl;
	
	int arr[2] = { 0,1 };
	int* ptr = &arr[0];
    *(ptr + 2) = 4;
	cout << arr[0] << endl;
	cout << arr[1] << endl;

	void* vPtr = &c;
	int a = 7;
	void* vPtr = &a;

	int arr[20]; //array on the stack
	int* arr1 = new int[20]; //array on the free store


}
