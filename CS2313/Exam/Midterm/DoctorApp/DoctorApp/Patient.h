
#include <string>
#include <vector>
#include "Billing.h"
#include "Doctor.h"

#ifndef PAT_H
#define PAT_H

using namespace std;

enum class Insurance { Medicare, BCBS, Aetna };
enum class Gender { Male, Female };

class Patient {
public:
	Patient(string& fn, string& ln, Insurance i, Gender s);
	void setDoctor(Doctor doc);
	void updateBilling(double bill);
	double getBilling() const;
private:
	const int MaxDoctors{ 2 };
	string firstName;
	string lastName;
	Insurance insurance;
	Gender gender;
	Billing bill;
	vector<Doctor> doctors{ MaxDoctors };
};

#endif