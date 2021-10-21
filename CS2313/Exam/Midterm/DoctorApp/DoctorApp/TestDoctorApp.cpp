
#include <iostream>
#include <stdexcept>
#include "Doctor.h"
#include "Patient.h"

using namespace std;

int main() {

	string lastName1 = "Grey";
	Doctor doc1(lastName1, Specialty::General);

	string lastName2 = "Webber";
	Doctor doc2(lastName2, Specialty::General);

	string lastName3 = "Robbins";
	Doctor doc3(lastName3, Specialty::Pediatrics);

	string lastName4 = "Karev";
	Doctor doc4(lastName4, Specialty::Pediatrics);

	string pfirstname1 = "Tom";
	string plastName1 = "Tom";
	Patient pat1(pfirstname1, plastName1, Insurance::Aetna, Gender::Male);

	try {
		pat1.setDoctor(doc1);
		pat1.setDoctor(doc2);
		pat1.setDoctor(doc3);
	}
	catch(exception& e) {
		cout << e.what() << endl;
	}
	//cout << "Patient's initial bill amount: $" << pat1.getBilling() << endl;
	pat1.updateBilling(100);
	cout << "Patient's bill amount after deductable: $" << pat1.getBilling() << endl;
	pat1.updateBilling(700);
	cout << "Patient's bill amount after deductable: $" << pat1.getBilling() << endl;
	return 0;
}