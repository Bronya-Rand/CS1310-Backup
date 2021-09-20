
#include <iostream>

using namespace std;

int main() {

	/* Error Test 1*/
	int* number{}; // fixed
	// error: needed to point address since value is uninitialized
	cout << number << endl; 

	/* Error Test 2*/
	double* realPtr;
	long* integerPtr;
	// error: can't add double * to long *
	// from old Programming I/II | Algorithm code
	integerPtr = (long*)&realPtr; // fixed?

	/* Error Test 3*/
	int* x, y;
	// error: can't set int * to int
	x = &y; // fixed

	/* Error Test 4*/
	char s[]{ "this is a character array" };
	// error: operands not compatible | expression needs modifiable value
	for (int t = 0; t != strlen(s); t++) {
		cout << *(s + t) << " ";
	}
	cout << endl;

	/* Error Test 5*/
	short* numPtr, result;
	void* genericPtr{ &numPtr };
	// error: operands not compatible | expression needs modifiable value
	result = *((short*)genericPtr + 7); // fixed?
	cout << endl;

	/* Error Test 6*/
	double xTestFive = 19.34; // x in problem but changed to avoid conflict
	double* xPtr{ &xTestFive }; // fixed
	// error: xPtr needed * to point properly with &
	cout << xPtr << endl;
	return 0;
}