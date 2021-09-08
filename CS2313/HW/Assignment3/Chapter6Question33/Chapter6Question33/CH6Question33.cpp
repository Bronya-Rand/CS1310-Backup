
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

int flip() {
	return rand() % 2;
}

int main() {
	int coin{};
	int heads{0};
	int tails{0};

	srand(time(NULL));
	
	for (int x = 1; x <= 100; x++) {
		coin = flip();

		cout << "Coin " << x << " was ";
		if (coin == 0) {
			cout << "heads!\n";
			heads += 1;
		}
		else {
			cout << "tails!\n";
			tails += 1;
		}
	}

	cout << "\nFrom 100 coin flips\n";
	cout << "---------------------------\n";
	cout << heads << " coins landed heads.\n";
	cout << tails << " coins landed tails.\n\n";
	return 0;
}