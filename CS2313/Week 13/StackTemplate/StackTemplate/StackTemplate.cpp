
#include <iostream>
#include <deque>
#include "Stack.h"

using namespace std;

int main() {
	deque<int> myList;
	cout << "----------------Using the standard deque class ----------------\n";
	myList.push_back(10);
	myList.push_back(20);
	myList.push_back(30);
	myList.push_back(40);
	myList.push_front(50);

	while (!myList.empty()) {
		cout << myList.front() << endl;
		myList.pop_front();
	}

	cout << "----------------Using the template class stack ----------------\n";
	Stack<int> intStack;
	intStack.push(11);
	intStack.push(22);
	intStack.push(33);
	intStack.push(44);
	intStack.push(55);

	while (!intStack.isEmpty()) {
		cout << intStack.top() << endl;
		intStack.pop();
	}
}