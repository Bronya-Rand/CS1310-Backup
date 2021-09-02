
#include <iostream>

#include ".\Student.h"

using namespace std;

int main() {
	Student student1{ "James Green", 93 };
	Student student2{ "Joyce White", 72 };

	cout << "Student Name \t Grade \n";
	cout << "-----------------------------------\n";
	cout << student1.getName() << "\t" << student1.getLetterName() << endl;
	cout << student2.getName() << "\t" << student2.getLetterName() << endl;

	return 0;
}