
#include <vector>
#include <string>

#ifndef INTSET_H
#define INTSET_H

class IntegerSet {
public:
	IntegerSet();
	IntegerSet(int array[]);
	void insertElement(int location);
	void deleteElement(int location);
	void inputValuesToSet();
	std::string toString();
	bool isEqualTo(IntegerSet setA);
	IntegerSet unionOfSets(IntegerSet& main, IntegerSet& back);
	IntegerSet intersectionOfSets(IntegerSet& main, IntegerSet& back);
private:
	std::vector<int> set{ 100 };
};

#endif