#include <string>

using namespace std;

class Student {
	string name;
	int average{ 0 };

public:

	//Constructor
	Student() {

	}

	Student(string studentName, int studentAverage) :name{ studentName } {
		if (studentAverage >= 0 && studentAverage <= 100) {
			average = studentAverage;
		}
	}

	string getName() const {
		return name;
	}

	int getAverage() {
		return average;
	}

	void setName(string studentName) {
		name = studentName;
	}

	void setAverage(int studentAverage) {
		if (studentAverage >= 0 && studentAverage <= 100) {
			average = studentAverage;
		}
	}

	string getLetterName() {
		string letterGrade;

		if (average >= 90) {
			letterGrade = "A";
		}
		else if (average >= 80) {
			letterGrade = "V";
		}
		else if (average >= 70) {
			letterGrade = "C";
		}
		else if (average >= 60) {
			letterGrade = "D";
		}
		else {
			letterGrade = "F";
		}

		return letterGrade;
	}
};