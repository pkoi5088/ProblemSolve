#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int h[3] = { 0 };
	int s[2] = { 0 };
	int T = 5000;

	for (int i = 0; i < 3; i++)
		cin >> h[i];
	for (int i = 0; i < 2; i++)
		cin >> s[i];

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			T = min(T, h[i] + s[j] - 50);
		}
	}
	cout << T;
	return 0;
}