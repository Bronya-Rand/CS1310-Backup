
#include <string>

#ifndef DOC_H
#define DOC_H

using namespace std;

enum class Specialty{General, Pediatrics};

class Doctor {
public:
	Doctor();
	Doctor(string& ln, Specialty s);
	void getDoctorInfo();
private:
	string lastName;
	Specialty specialty;
};

#endif