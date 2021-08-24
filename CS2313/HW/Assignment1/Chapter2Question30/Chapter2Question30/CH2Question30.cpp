
#include <iostream>

using namespace std;

int main()
{
	char measure{};
	int height{};
	int weight{};
	double bmi{};

	cout << "Would you like to measure your BMI in meters/KG or inches/LB (m/i)?: ";
	cin >> measure;

	cout << "How tall are you? (numbers only): ";
	cin >> height;

	cout << "How much do you weigh? (numbers only): ";
	cin >> weight;

	if (measure == 'i' || measure == 'I') {
		bmi = (weight * 703) / (height * height);
	}
	else {
		bmi = weight / (height * height);
	}

	if (bmi >= 30) {
		cout << "Based off your weight and height, you are obese according to the BMI scale.\n";
	}
	else if (bmi >= 25 && bmi < 30) {
		cout << "Based off your weight and height, you are overweight according to the BMI scale.\n";
	}
	else if (bmi >= 18.5 && bmi < 25) {
		cout << "Based off your weight and height, you BMI levels are normal.\n";
	}
	else {
		cout << "Based off your weight and height, you are underweight according to the BMI scale.\n";
	}
}