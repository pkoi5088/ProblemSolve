#include <iostream>

using namespace std;

int main() {
	int re = 0;
	int X = 0;
	cin >> X;
	while (X != 0) {
		re += X % 2;
		X /= 2;
	}
	cout << re;
	return 0;
}