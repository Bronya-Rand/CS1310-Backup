
#include "Billing.h"
#include <stdexcept>

Billing::Billing(double b) :bill{ b } {
	bill = b;
}

void Billing::setBill(double nb) {
	if (nb < 0.0) {
		throw std::invalid_argument("The value you submitted is invalid. Please try again.");
	}
	else {
		bill = nb;
	}
}

void Billing::addBill(double ac) {
	if (ac < 0.0) {
		throw std::invalid_argument("The value you submitted is invalid. Please try again.");
	}
	else {
		bill += ac;
	}
}

double Billing::getBill() const {
	return bill;
}