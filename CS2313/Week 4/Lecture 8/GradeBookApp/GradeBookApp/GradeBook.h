
#include <string>
#include <iostream>
#include <array>

using namespace std;

class GradeBook {
public:
	const static int numOfStudents{ 10 };
	GradeBook(const string& name, array<int, numOfStudents> gradesArray) :courseName{ name }, studentGrades{ gradesArray } {

	}

	void setCourseName(const string& name) {
		courseName = name;
	}

	const string& getCourseName() const {
		return courseName;
	}

	void processGrades() {
		for (size_t i{ 0 }; i < studentGrades.size(); i++) {
			cout << "Student " << (i + 1) << ": " << studentGrades[i] << endl;
		}
		cout << endl << endl;
		cout << "Max Grade: " << getMaxGrade() << endl;
		cout << "Min Grade: " << getMinGrade() << endl;
		cout << "Total Grade: " << getTotalGrade() << endl;
		cout << "Average Grade: " << static_cast <double> (getTotalGrade()) / numOfStudents << endl;
	}

private:
	string courseName;
	array<int, numOfStudents> studentGrades;

	//Helper functions
	int getMaxGrade() {
		int maxGrade{ 0 };

		for (int grade : studentGrades) {
			if (grade > maxGrade) {
				maxGrade = grade;
			}
		}

		return maxGrade;
	}

	int getMinGrade() {
		int minGrade{ 100 };

		for (int grade : studentGrades) {
			if (grade < minGrade) {
				minGrade = grade;
			}
		}

		return minGrade;
	}

	int getTotalGrade() {
		int total{ 0 };

		for (int grade : studentGrades) {
			total += grade;
		}

		return total;
	}
};