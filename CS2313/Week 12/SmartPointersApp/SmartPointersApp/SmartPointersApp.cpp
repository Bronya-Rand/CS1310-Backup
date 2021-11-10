
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
	//Step 1

	int* x = new int{ 10 };
	int* y = x;

	cout << "x = " << x << "\t" << "*x = " << *x << endl;
	cout << "y = " << y << "\t" << "*y = " << *y << endl;

	delete x;
	//delete y; //EXCEPTION: the location is already deleted
	cout << "--------------------------------------------\n";
	unique_ptr<int> smartX = make_unique<int>(20);
	unique_ptr<int> smartY;

	cout << "smartX = " << smartX << "\t" << "*smartX = " << *smartX << endl;

	smartY = move(smartX);
	cout << "smartY = " << smartY << "\t" << "*smartY = " << *smartY << endl;
	cout << "smartX = " << smartX << "\tsmartX is pointing to nothing because we moved ownership" << endl;
	cout << "--------------------------------------------\n";

	//Step 2
	double* ptr1 = new double{ 10.75 };
	cout << "ptr1 = " << ptr1 << "\t\t *ptr1 = " << *ptr1 << endl;

	unique_ptr<double> smartPtr1 = make_unique<double>(12.95);
	cout << "smartPtr1 = " << ptr1 << "\t\t *smartPtr1 = " << *ptr1 << endl;

	delete ptr1;

	cout << "--------------------------------------------\n";

	//Step 3
	double* ptr2 = new double[3];
	ptr2[0] = 10.5;
	ptr2[1] = 11.5;
	ptr2[2] = 12.5;

	for (int i = 0; i < 3; i++) {
		cout << "ptr2[" << i << "] = " << ptr2[i] << "\t ====> Address = " << &ptr2[i] << endl;
	}
	delete[] ptr2;

	unique_ptr<double> smartPtr2[3];

	smartPtr2[0] = make_unique<double>(20.5);
	smartPtr2[1] = make_unique<double>(30.5);
	smartPtr2[2] = make_unique<double>(40.5);

	for (int i = 0; i < 3; i++) {
		cout << "smartPtr2[" << i << "] = " << smartPtr2[i] << "\t\t*smartPtr2[i] = " << *smartPtr2[i] << endl;
	}

	//Step 4
	double* ptr3[50];
	size_t i;
	try {
		for (i = 0; i < 50; i++) {
			ptr3[i] = new double[50'000'000];
			cout << "ptr3[" << i << "] is pointing to 50,000.000 doubles" << endl;
		}
	}
	catch (bad_alloc& e) {
		cout << "Exception occured: " << e.what() << endl;

		for (int j = 0; j < i; j++) {
			delete[] ptr3[j];
		}
	}

	unique_ptr<double[]> smartPtr3[50];

	try {
		for (i = 0; i < 50; i++) {
			smartPtr3[i] = make_unique<double[]>(50'000'000);
			cout << "smartPtr3[" << i << "] is pointing to 50,000.000 doubles" << endl;
		}
	}
	catch (bad_alloc& e) {
		cout << "Exception occured: " << e.what() << endl;
	}
}