
#include <iostream>
#include <string>
#include <array>
#include <iomanip>

using namespace std;

int main() {
	
	string topics[5]{ "Rate the current administration", "Rate state decisions", "Rate the govenor", "Rate republicans", "Rate democrats" };
	array<array<int, 10>, 5> pollArray{};
	int count{1};
	int person{ 1 };
	int results{};
	int i{};
	int j{};
	array<int, 5> averages{};

	while (person <= 2) {
		count = 1;
		while (count <= 5) {
			cout << "Person " << person << ", " << topics[count - 1] << " (integers only): ";
			cin >> results;
			averages[count - 1] += results;
			if (results < 0 || results > 10) {
				cout << "Invalid rating. Please try again.\n\n";
			}
			else {
				for (i = 1; i <= 10; i++) {
					if (i == results) {
						pollArray[count - 1][i - 1] += 1;
					}
				}
				count++;
			}
		}
		person++;
		cout << endl;
	}

	cout << fixed << setprecision(2);
	cout << "Topic #" << setw(10) << "1" << setw(5) << "2"  << setw(5) << "3" << setw(5) << "4" << setw(5) << "5" << setw(5) << "6" << setw(5) << "7" << setw(5) << "8" << setw(5) << "9" << setw(6) << "10\n";
	for (i = 1; i <= 5; i++) {
		cout << setw(5) << i << setw(12);
		for (j = 1; j <= 10; j++) {
			if (pollArray[i - 1][j - 1] == 0) {
				cout << "0" << setw(5);
			}
			else {
				cout << pollArray[i - 1][j - 1] << setw(5);
				averages[i - 1] += j;
			}
		}

		cout << setw(10) << 5.0 / averages[i - 1] * 100 << "%\n";
	}

	int maxTopic{ 1 };
	int minTopic{ 1 };
	for (i = 0; i <= 4; i++) {
		if (averages[i] < averages[maxTopic - 1]) {
			maxTopic = i + 1;
		}
		else if (averages[i] > averages[minTopic - 1]) {
			minTopic = i + 1;
		}
	}

	cout << "\nThe highest point total topic was Topic " << maxTopic << " with " << static_cast<double>(5.0 / averages[maxTopic - 1] * 100) << "% of the votes.\n";
	cout << "The lowest point total topic was Topic " << minTopic << " with " << static_cast<double>(5.0 / averages[minTopic - 1] * 100) << "% of the votes.\n";
	return 0;
}