
#include <iostream>

using namespace std;

int main() {
	int total{ 0 };
	int grade;
	int average{ 0 };
	int gradeCounter{ 1 };

	while (gradeCounter <= 5) {
		cout << "Enter a grade: ";
		cin >> grade;
		total += grade; // total = total + grade
		gradeCounter++;
	}
	cout << endl << endl;

	average = total / gradeCounter - 1; //this will truncate any decimal values
	cout << "Total = " << total << endl;
	cout << "Average = " << total / 5.0 << endl;
	cout << "--------------------------------------";
	int x = INT_MAX;
	cout << "MAX INT = " << x << endl;

	return 0;
}