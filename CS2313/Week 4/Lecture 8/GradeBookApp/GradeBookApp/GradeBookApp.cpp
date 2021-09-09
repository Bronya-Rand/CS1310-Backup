
#include "GradeBook.h"

int main() {

	string courseName{ "Object Oriented Programming I" };
	array<int, GradeBook::numOfStudents> grades{ 20, 35, 70, 80, 90, 74, 62, 100, 66, 54 };

	GradeBook myGradeBook{courseName, grades};
	myGradeBook.processGrades();
	return 0;
}