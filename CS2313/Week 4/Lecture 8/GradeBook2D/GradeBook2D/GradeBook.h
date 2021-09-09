
#include <string>
#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

class GradeBook {
public:
	const static int numOfStudents{ 10 };
	const static int numOfTests{ 3 };

	GradeBook(const string& name, array<array<int, numOfTests>, numOfStudents>& gradesArray) :courseName{ name }, studentsGrades{ gradesArray } {

	}

	void setCourseName(const string& name) {
		courseName = name;
	}

	const string& getCourseName() {
		return courseName;
	}

	void processGrades() {
		cout << setw(20) << "Test 1" << setw(20) << "Test 2" << setw(20) << "Test 3" << setw(10) << "Average\n";

		for (int student{ 0 }; student < numOfStudents; student++) {
			cout << "Student " << setw(2) << student + 1;

			for (int test = 0; test < numOfTests; test++) {
				cout << setw(15) << studentsGrades[student][test];
			}

			double average = getAverage(studentsGrades[student]);
			cout << fixed << setprecision(2) << setw(10) << average << endl;
		}
	}

private:
	string courseName;
	array<array<int, numOfTests>, numOfStudents> studentsGrades;

	double getAverage(array<int, numOfTests> row) {
		int total{ 0 };
		
		for (auto item : row) {
			total += item;
		}
		
		return static_cast <double> (total) / row.size();
	}
};