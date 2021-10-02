
#include <array>
#include <string>

#ifndef HINT_H
#define HINT_H

class HugeInteger {
	friend bool isEqualTo(HugeInteger& h1, HugeInteger& h2);
	friend bool isNotEqualTo(HugeInteger& h1, HugeInteger& h2);
	friend bool isGreaterThan(HugeInteger& h1, HugeInteger& h2);
	friend bool isGreaterThanOrEqualTo(HugeInteger& h1, HugeInteger& h2);
	friend bool isLessThan(HugeInteger& h1, HugeInteger& h2);
	friend bool isLessThanOrEqualTo(HugeInteger& h1, HugeInteger& h2);
public:
	HugeInteger();
	void input(int i, int val);
	void output();
	std::string add(int addBy);
	std::string subtract(int subBy);
private:
	std::array<int, 40> integerArray;
};

#endif