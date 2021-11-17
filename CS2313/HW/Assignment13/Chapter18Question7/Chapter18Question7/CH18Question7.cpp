
#include <iostream>

using namespace std;
template <typename T>

T add(T a, T b) {
	return a + b;
}

int main() {
	int a = 5;
	int a2 = 5;
	double b = 5.13;
	float c = 5.13f;
	char d = 'd';
	int d2 = 3;

	cout << add(a, a2) << endl;
	cout << add<double>(b, c) << endl;
	cout << add<char>(d, d2) << endl;
}