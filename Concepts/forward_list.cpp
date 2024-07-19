#include<iostream>
#include<forward_list>
#include<vector>

void PrintList(const std::forward_list<int>& list) {
	std::cout << std::endl;
	for (auto x : list) std::cout << x << " ,";
}

int main() {
	std::forward_list<int> Flist;
	Flist = { 1,2,3 };
	PrintList(Flist);
	Flist.assign(4, 4);
	PrintList(Flist);

	Flist.push_front(0);
	PrintList(Flist);

	auto pos = begin(Flist);
	std::advance(pos, 3);
	int distance = std::distance(begin(Flist), end(Flist));
	//std::cout << distance << std::endl;
	Flist.insert_after(pos, distance-1);
	PrintList(Flist);

	Flist.push_front(2);
	Flist.push_front(2);
	Flist.push_front(2);
	Flist.push_front(2);
	PrintList(Flist);
	Flist.unique();
	PrintList(Flist);

}
