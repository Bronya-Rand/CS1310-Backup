#ifndef STACK_H
#define STACK_H

#include <deque>

using namespace std;

template<typename T>

class Stack 
{
public:
	//functions
	void push(const T& x) {
		list.push_front(x);
	}
	void pop() {
		list.pop_front();
	}
	T& top() {
		return list.front();
	}
	bool isEmpty() {
		return list.empty();
	}
	size_t size() {
		return list.size();
	}
private:
	deque<T> list;
};

#endif