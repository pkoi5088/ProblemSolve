#include <iostream>

using namespace std;

int main() {
	int x, y, days = 0;
	cin >> x >> y;
	for (int i = 1; i < x; i++) {
		switch (i) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			days += 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			days += 30;
			break;
		default:
			days += 28;
			break;
		}
	}
	days += y - 1;
	switch (days % 7) {
	case 6:
		cout << "SUN";
		break;
	case 0:
		cout << "MON";
		break;
	case 1:
		cout << "TUE";
		break;
	case 2:
		cout << "WED";
		break;
	case 3:
		cout << "THU";
		break;
	case 4:
		cout << "FRI";
		break;
	case 5:
		cout << "SAT";
		break;
	}
	return 0;
}