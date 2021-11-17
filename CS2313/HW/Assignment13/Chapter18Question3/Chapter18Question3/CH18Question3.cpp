
#include <iostream>
#include "Equal.h"

using namespace std;

template<typename T>

bool isEqualTo(T arg1, T arg2) {
	if (arg1 == arg2) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	cout << "\n ------------ Non-Class | Same args type ---------------\n";

	cout << "Int (2, 2): " << isEqualTo(2, 2) << endl;
	cout << "Double (2.20, 2.14): " << isEqualTo(2.20, 2.14) << endl;
	cout << "Float (2.465, 2.456): " << isEqualTo(2.465f, 2.456f) << endl;
	cout << "Char ('A', 'A'): " << isEqualTo('A', 'A') << endl;
	cout << "Bool (true, true): " << isEqualTo(true, true) << endl << endl;

	cout << "------------ Non-Class | Different args type ---------------\n";

	cout << "Int (2, b): " << isEqualTo<int>(2, 'b') << endl;
	cout << "Double (2.0, false) " << isEqualTo<double>(2.0, false) << endl;
	cout << "Float (2.465, 1): " << isEqualTo<float>(2.465f, 1) << endl;
	cout << "Char ('A', 41): " << isEqualTo<char>('A', 41) << endl;
	cout << "Bool (true, 1): " << isEqualTo<bool>(true, 1) << endl << endl;
	
	cout << "------------ Class Equal To ---------------\n";

	Equal<int> a1(1, 5);
	Equal<double> a2(2.5, 2.5);
	Equal<float> a3(2.465f, 2.8f);
	Equal<char> a4('A', 'a');
	Equal<bool> a5(false, 1);

	cout << "Int (1, 5): " << a1.isEqualTo() << endl;
	cout << "Double (2.5, 2.5) " << a2.isEqualTo() << endl;
	cout << "Float (2.465, 2.8): " << a3.isEqualTo() << endl;
	cout << "Char ('A', 'a'): " << a4.isEqualTo() << endl;
	cout << "Bool (false), 1): " << a5.isEqualTo() << endl << endl;
	
	cout << "------------ Class Overload ---------------\n";

	Equal<int> test(2, 2);
	cout << "Int [Overload] (2, 2): " << (test.getArgOne() == test.getArgTwo()) << endl;
	Equal<double> test2(2.5, 2);
	cout << "Double [Overload] (2.5, 2): " << (test2.getArgOne() == test2.getArgTwo()) << endl;
	Equal<float> test3(2.465f, 2.465f);
	cout << "Float [Overload] (2.465, 2.465): " << (test3.getArgOne() == test3.getArgTwo()) << endl;
	Equal<char> test4('A', 2);
	cout << "Char [Overload] (A, 2): " << (test4.getArgOne() == test4.getArgTwo()) << endl;
	Equal<bool> test5(true, 1);
	cout << "Bool [Overload] (true, 1): " << (test5.getArgOne() == test5.getArgTwo()) << endl;
}

