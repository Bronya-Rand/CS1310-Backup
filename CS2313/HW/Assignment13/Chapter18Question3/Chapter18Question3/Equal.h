
#ifndef EQUAL_H
#define EQUAL_H

template<typename T>

class Equal
{
public:
	Equal(T val1, T val2) {
		arg1 = val1;
		arg2 = val2;
	}
	bool isEqualTo() {
		if (arg1 == arg2) {
			return true;
		}
		else {
			return false;
		}
	}
	T getArgOne() {
		return arg1;
	}
	T getArgTwo() {
		return arg2;
	}
	bool operator==(const Equal& c) {
		Equal temp{ *this };
		return (temp.arg1 == c.arg1 && temp.arg2 == c.arg2);
	}
private:
	T arg1;
	T arg2;
};

#endif