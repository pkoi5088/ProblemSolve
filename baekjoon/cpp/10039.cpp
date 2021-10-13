#include <iostream>

using namespace std;

int main() {
	int m[5] = { 0 };
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> m[i];
		if (m[i] < 40)
			m[i] = 40;
		sum += m[i];
	}
	cout << sum / 5;
	return 0;
}