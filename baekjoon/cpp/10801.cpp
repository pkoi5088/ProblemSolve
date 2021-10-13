#include <iostream>

using namespace std;

int main() {
	int ac[10], bc[10], aw = 0, bw = 0;
	for (int i = 0; i < 10; i++)
		cin >> ac[i];
	for (int i = 0; i < 10; i++)
		cin >> bc[i];

	for (int i = 0; i < 10; i++) {
		if (ac[i] > bc[i])
			aw++;
		else if (ac[i] < bc[i])
			bw++;
	}

	if (aw > bw)
		cout << 'A';
	else if (aw < bw)
		cout << 'B';
	else
		cout << 'D';
	return 0;
}