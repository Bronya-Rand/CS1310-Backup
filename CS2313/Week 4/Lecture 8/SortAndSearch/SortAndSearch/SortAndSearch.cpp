
#include <iostream>
#include <iomanip>
#include <array>
#include <algorithm>

using namespace std;

int main() {
	const size_t arraySize{ 7 };
	array<int, arraySize> numbers{ 13, 15, 22, -7, 8, 9, 4 };

	// output original array
	cout << "Unsorted Array:\n";
	for (int num : numbers) {
		cout << num << " ";
	}

	sort(numbers.begin(), numbers.end());

	//output sorted array
	cout << "Sorted Array:\n";
	for (int num : numbers) {
		cout << num << " ";
	}

	return 0;
}
