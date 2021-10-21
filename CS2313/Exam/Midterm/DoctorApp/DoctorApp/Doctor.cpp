
#include "Doctor.h"
#include <string>
#include <iostream>

Doctor::Doctor()
{
}

Doctor::Doctor(string& ln, Specialty s) :lastName{ln}, specialty{s}
{
	
}

void Doctor::getDoctorInfo() {
	string docSpeciality = (specialty == Specialty::General ? "General" : "Pediatrics");
	std::cout << "Doctor Last Name: " << lastName << std::endl;
	std::cout << "Doctor Specialty: " << docSpeciality << std::endl;
}

