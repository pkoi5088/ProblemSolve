#include <iostream>

using namespace std;

int main() {
	int m[4] = { 0 };
	for (int T = 0; T < 3; T++) {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			cin >> m[i];
			if (m[i])
				cnt++;
		}
		switch (cnt) {
		case 0:
			cout << 'D';
			break;
		case 1:
			cout << 'C';
			break;
		case 2:
			cout << 'B';
			break;
		case 3:
			cout << 'A';
			break;
		case 4:
			cout << 'E';
			break;
		}
		cout << endl;
	}
	return 0;
}