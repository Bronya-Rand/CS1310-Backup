
#include <iostream>
#include <random>

using namespace std;

int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	for (int x = 0; x < 10; x++) {
		int i{ rand() % 100 + 1 };
		double j{ rand() % 100 + 1.0 };
		try {
			false ? throw i : throw j;
		}
		catch (int& e) {
			cout << "int catch was engaged" << endl;
		}
		catch (double& e) {
			cout << "double catch was engaged" << endl;
		}
	}
}