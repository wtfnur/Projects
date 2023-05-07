#include <iostream>
#include <string>
#include "list.h"
#include "list.cpp"


void test();

int main(){

	test();
	return 0;
}

void test() {

	DictionaryList<std::string> list1;
	std::string a, b, c, d, e, f;
	std::cout << "input 6 str:";
	std::cin >> a >> b >> c >> d >> e >> f;

	list1.insert(a);
	list1.insert(b);
	list1.insert(c);
	std::cout << "\nCopy \nBefore\nList1: " << list1 << "\nList2: Not initialized\n\nAfter copy\n";
	DictionaryList<std::string> list2(list1);
	std::cout << "List1: " << list1 << "\nList2: " << list2 << "\n\n\n";
	std::cout << "Move\nBefore\nList1: " << list1 << "\nList3: Not  initialized\n\nAfter move\n";
	DictionaryList<std::string> list3(move(list1));
	std::cout << "List1: " << list1 << "\nList3: " << list3 << "\n\n\n";
	std::cout << "insert\nBefore: " << list1 << "\nAfter insert: ";
	list1.insert(a);
	list1.insert(b);
	list1.insert(d);
	std::cout << list1;
	std::cout << "\n\n\nMethod deleted\nBefore: " << list1 << "\nAfter deleted: ";
	list1.deleted(a);
	std::cout << list1 << "\n\n\n";
	std::cout << "Search in list1 ";
	std::cout << "\nSearch(a): ";
	list1.search(a);
	std::cout << "\nSearch(b): ";
	list1.search(b);
	std::cout << "\nSearch(c): ";
	list1.search(c);
	std::cout << "\nSearch(d): ";
	list1.search(d);

	std::cout << "\n\n\n";

	std::cout << "Merge\nBefore\nList1: " << list1 << "\nList2: " << list2 << "\n\nAfter merge\n";
	list1.merge(list2);
	std::cout << "List1: " << list1 << "\nList2: " << list2 << "\n\n\n";
	list2.insert(e);
	list2.insert(f);
	list2.insert(a);
	list2.insert(b);
	std::cout << "Method remove_list\nBefore\nList1: " << list1 << "\nList2: " << list2 << "\n\nAfter remove_list\n";
	list1.remove_list(list2);
	std::cout << "List1: " << "\nList2: " << list2 << "\n\n\n";
	list2.insert(c);
	list2.insert(d);
	list2.insert(e);
	std::cout << "getIntersection\nBefore:\nList1: " << list1 << "\nList2: " << list2 << "\n\nAfter intersection\n";
	list3 = getIntersection(list1, list2);
	std::cout << "List3: " << list3;
	

}
