
#include <iostream>

using namespace std;

template <typename minimum>
minimum minArgs(minimum argA, minimum argB) {
	if (argA < argB) {
		return argA;
	}
	else {
		return argB;
	}
}

int main() {
	int val1{};
	int val2{};
	char char1{};
	char char2{};
	float float1{};
	float float2{};

	cout << "Enter two integers: ";
	cin >> val1 >> val2;

	cout << "The minimum argurment between " << val1 << " and " << val2 << " is " << minArgs<int>(val1, val2) << endl;

	cout << "Enter two characters: ";
	cin >> char1 >> char2;

	cout << "The minimum argurment between " << char1 << " and " << char2 << " is " << minArgs<char>(char1, char2) << endl;

	cout << "Enter two floats: ";
	cin >> float1 >> float2;

	cout << "The minimum argurment between " << float1 << " and " << float2 << " is " << minArgs<float>(float1, float2) << endl;

	return 0;
}