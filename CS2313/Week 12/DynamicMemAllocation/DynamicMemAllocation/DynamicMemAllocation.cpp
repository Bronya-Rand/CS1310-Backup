
#include <iostream>

using namespace std;

int main() {
	double* doublePtr = new double{ 20 };
	cout << doublePtr << " " << *doublePtr << endl;
	delete doublePtr;
	cout << "------------------------------------\n";

	double* doublePtr2 = new double[3]; //dynamic array

	doublePtr2[0] = 10.5;
	doublePtr2[1] = 11.5;
	doublePtr2[2] = 12.5;

	for (int i = 0; i < 3; i++) {
		cout << doublePtr2[i] << endl;
	}

	//free doublePtr2
	delete[] doublePtr2;
	cout << "------------------------------------\n";

	double* doublePtr3[2];
	doublePtr3[0] = new double[3];
	doublePtr3[1] = new double[3];

	doublePtr3[0][0] = 100.1; doublePtr3[0][1] = 200.1; doublePtr3[0][2] = 300.1;
	doublePtr3[1][0] = 400.1; doublePtr3[1][1] = 500.1; doublePtr3[1][2] = 600.1;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << doublePtr3[i][j] << "   ";
		}
		cout << endl;
	}

	//free doublePtr3
	delete[] doublePtr3[0];
	delete[] doublePtr3[1];
	return 0;
}