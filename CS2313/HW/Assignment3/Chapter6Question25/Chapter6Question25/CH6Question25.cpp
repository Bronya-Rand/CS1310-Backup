
#include <iostream>

using namespace std;

int secondsAfterTwelve(int hour, int minute, int second, char timeLetter) {
	int twelvePM = (12 * 3600);
	if (hour == 12) {
		return 0 + (minute * 60) + second;
	}
	else if (timeLetter == 'a' || timeLetter == 'A') {
		return (hour * 3600) + (minute * 60) + second;
	}
	else {
		return (((hour + 12) * 3600) - twelvePM) + (minute * 60) + second;
	}
}

int main() {
	int hours{};
	int minutes{-1};
	int seconds{-1};
	char letter{'b'};

	while (hours <= 0 || hours > 12) {
		cout << "Please enter the hour: ";
		cin >> hours;
	}

	while (minutes < 0 || minutes > 59) {
		cout << "Please enter the minute: ";
		cin >> minutes;
	}

	while (seconds < 0 || seconds > 59) {
		cout << "Please enter the second: ";
		cin >> seconds;
	}

	while (letter != 'a' && letter != 'A' && letter != 'p' && letter != 'P') {
		cout << "Is the time in AM or PM? (A/P): ";
		cin >> letter;
	}

	cout << "The last time the clock struck 12 was " << secondsAfterTwelve(hours, minutes, seconds, letter) << " seconds ago.\n";
	return 0;
}