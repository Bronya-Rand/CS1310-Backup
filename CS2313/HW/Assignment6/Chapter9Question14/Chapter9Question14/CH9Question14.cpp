
#include "HugeInteger.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

bool isEqualTo(HugeInteger& h1, HugeInteger& h2) {
	return (h1.integerArray == h2.integerArray);
}

bool isNotEqualTo(HugeInteger& h1, HugeInteger& h2) {
	return (h1.integerArray != h2.integerArray);
}

bool isGreaterThan(HugeInteger& h1, HugeInteger& h2) {
	return (h1.integerArray > h2.integerArray);
}

bool isGreaterThanOrEqualTo(HugeInteger& h1, HugeInteger& h2) {
	return (h1.integerArray >= h2.integerArray);
}

bool isLessThan(HugeInteger& h1, HugeInteger& h2) {
	return (h1.integerArray < h2.integerArray);
}

bool isLessThanOrEqualTo(HugeInteger& h1, HugeInteger& h2) {
	return (h1.integerArray <= h2.integerArray);
}


int main() {
	int temp{};
	srand(static_cast<unsigned int>(time(NULL)));

	HugeInteger huge1;
	cout << "The output of this huge integer is: ";
	huge1.output();
	cout << endl << endl;
	cout << huge1.add(73);
	cout << endl << endl;
	cout << huge1.subtract(5);
	cout << endl << endl;

	HugeInteger huge2;
	cout << "The output of this huge integer is: ";
	huge2.output();
	cout << endl << endl;
	cout << huge2.add(21);
	cout << endl << endl;

	cout << "Equal?: " << isEqualTo(huge1, huge2) << endl;
	cout << "Not Equal?: " << isNotEqualTo(huge1, huge2) << endl;
	cout << "Greater Than?: " << isGreaterThan(huge1, huge2) << endl;
	cout << "Greater Than Or Equal To?: " << isGreaterThanOrEqualTo(huge1, huge2) << endl;
	cout << "Less Than?: " << isLessThan(huge1, huge2) << endl;
	cout << "Less Than or Equal To?: " << isLessThanOrEqualTo(huge1, huge2) << endl;
	return 0;
}