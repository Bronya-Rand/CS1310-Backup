
#include <iostream>

using namespace std;

int main() {

	int grade;
	int total{ 0 };
	int gradeCounter{ 0 };
	int acount{ 0 };
	int bcount{ 0 };
	int ccount{ 0 };
	int dcount{ 0 };
	int fcount{ 0 };

	cout << "Enter students grades 0 ... 100 <Ctrl> Z to quit \n";

	while (cin >> grade)
	{
		total += grade;
		gradeCounter++;

		switch (grade / 10)
		{
			case 9:
			case 10:
				acount++;
			
		}
	}

	return 0;
}