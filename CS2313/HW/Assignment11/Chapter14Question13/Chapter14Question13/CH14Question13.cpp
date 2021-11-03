
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
#include <iomanip>

using namespace std;

int main() {
	ofstream fileSizes{ "data-size.dat", ios::out };

	char charSize;
	unsigned char uCharSize;
	short int shortSize;
	unsigned short int uShortSize;
	int intSize;
	unsigned int uIntSize;
	long int lIntSize;
	unsigned long int uLIntSize;
	long long int llIntSize;
	unsigned long long int uLlIntSize;
	float floatSize;
	double doubleSize;
	long double lDoubleSize;

	if (!fileSizes) {
		cerr << "Cannot open file 'oldmast.dat'.";
		exit(EXIT_FAILURE);
	}
	
	fileSizes << left << setw(24) << "Type" << setw(24) << "Size" << endl;
	fileSizes << left << setw(25) << "char" << setw(25) << sizeof(charSize) << endl;
	fileSizes << left << setw(25) << "unsigned char" << setw(25) << sizeof(uCharSize) << endl;
	fileSizes << left << setw(25) << "short int" << setw(25) << sizeof(shortSize) << endl;
	fileSizes << left << setw(25) << "unsigned short int" << setw(25) << sizeof(uShortSize) << endl;
	fileSizes << left << setw(25) << "int" << setw(25) << sizeof(intSize) << endl;
	fileSizes << left << setw(25) << "unsigned int" << setw(25) << sizeof(uIntSize) << endl;
	fileSizes << left << setw(25) << "long int" << setw(25) << sizeof(lIntSize) << endl;
	fileSizes << left << setw(25) << "unsigned long int" << setw(25) << sizeof(uLIntSize) << endl;
	fileSizes << left << setw(25) << "long long int" << setw(25) << sizeof(llIntSize) << endl;
	fileSizes << left << setw(25) << "unsigned long long int" << setw(25) << sizeof(uLlIntSize) << endl;
	fileSizes << left << setw(25) << "float" << setw(25) << sizeof(floatSize) << endl;
	fileSizes << left << setw(25) << "double" << setw(25) << sizeof(doubleSize) << endl;
	fileSizes << left << setw(25) << "long double" << setw(25) << sizeof(lDoubleSize) << endl;
	return 0;
}