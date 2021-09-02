
#include <iostream>

using namespace std;

unsigned long factorialLoop(int n) {
	unsigned long factorialValue{ 1 };
	
	for (int i = 1; i <= n; i++) {
		factorialValue *= i;
	}

	return factorialValue;
}

unsigned long factorial(int n) {
	if (n == 1) {
		return 1;
	}

	return n * factorial(n - 1);
}

int main() {
	cout << "5! = " << factorialLoop(5) << endl;
	cout << "5! = " << factorial(5) << endl;
	return 0;
}