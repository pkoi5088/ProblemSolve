#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	n = n % 8;
	switch (n) {
	case 1:
		cout << 1;
		break;
	case 0:
	case 2:
		cout << 2;
		break;
	case 7:
	case 3:
		cout << 3;
		break;
	case 6:
	case 4:
		cout << 4;
		break;
	case 5:
		cout << 5;
		break;
	}
	return 0;
}