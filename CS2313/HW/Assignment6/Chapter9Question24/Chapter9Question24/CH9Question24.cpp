
#include <iostream>
#include "IntegerSet.h"

using namespace std;

int main() {
	IntegerSet a;
	IntegerSet b;
	IntegerSet c;
	IntegerSet d;
	a.inputValuesToSet();
	cout << endl << a.toString() << endl;
	cout << endl << endl;
	b.inputValuesToSet();
	cout << endl << b.toString() << endl << endl;
	c = a.unionOfSets(b, c);
	cout << c.toString() << endl << endl;
	d = a.intersectionOfSets(b, d);
	cout << d.toString() << endl << endl;

	cout << "A=B Equal?: " << a.isEqualTo(b) << endl;
	cout << "A=C Equal?: " << a.isEqualTo(c) << endl;
	cout << "A=D Equal?: " << a.isEqualTo(d) << endl;
	cout << "B=C Equal?: " << b.isEqualTo(c) << endl;
	cout << "B=D Equal?: " << b.isEqualTo(d) << endl;
	cout << "C=D Equal?: " << c.isEqualTo(d) << endl;
	return 0;
}