
#include "Patient.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Patient::Patient(string& fn, string& ln, Insurance i, Gender g) :firstName{ fn }, lastName{ ln }, insurance{ i }, gender{ g } {
	bill = Billing{};
}
void Patient::setDoctor(Doctor doc) {
	if (doctors.size() == MaxDoctors) {
		throw invalid_argument("This patient has visited two doctors already!");
	}
	else {
		doctors.push_back(doc);
	}
}
void Patient::updateBilling(double c) {
	bill.addBill(c);
}
double Patient::getBilling() const {
	double total = bill.getBill();
	if (total > 500.0 && (Insurance::Aetna == insurance || Insurance::BCBS == insurance)) {
		total -= 500.0;
	} else {
		if (total > 200.0) {
			total -= 200.0;
		}
	}
	return total;
}