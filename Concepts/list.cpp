#include<iostream>
#include<list>

void printList(const std::list<int>& List) {

	for (auto x : List) {
		std::cout << x << std::endl;
	}
}

int main() {
	std::list<int> List;
	List.push_back(1);
	List.push_back(2);
	printList(List);
	std::cout << std::endl;
	List.insert(begin(List), 0);
	printList(List);
	std::cout << std::endl;
	List.insert(end(List), 4);
	printList(List);

	auto it = cbegin(List);
	it = std::next(it, List.size()/2);
	List.insert(it, 10);
	printList(List);

	it = cbegin(List);
	std::advance(it, List.size() / 2);
	std::cout << "middle : " << *it << std::endl;

	List.sort();
	printList(List);
	List.reverse();
	List.remove_if([](int n) { return n < 1; });
	printList(List);

	for (std::list<int>::reverse_iterator it = List.rbegin(); it != List.rend(); it++) {
		std::cout << std::endl;
		std::cout << "reverse : " << *it << std::endl;

	}


	List.reverse();
	std::list<int> List2 = { 2,3,10 };
	List2.sort();

	List.merge(List2);
	printList(List);
	std::cout << std::endl;
	printList(List2);


	//splice example 
	std::list<int> List3{ 3,5,8 };
	auto list3_iter = List3.begin();
	std::advance(list3_iter, 2);
	List.splice(end(List),List3);
	printList(List);
	std::cout << std::endl;
	List.splice(end(List), List3, list3_iter, end(List3));
	printList(List);



}
