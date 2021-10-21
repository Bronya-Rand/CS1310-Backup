
#ifndef BIL_H
#define BIL_H

using namespace std;

class Billing {
public:
	Billing(double b = 0);
	void setBill(double nb);
	void addBill(double ac);
	double getBill() const;
private:
	double bill;
};

#endif