#include <iostream>

using namespace std;

int function(int f) {
	int i = 1;
	int c = f;
	while (c != 1) {
		if (c % 2 == 0) {
			i++;
			c /= 2;
		}
		else {
			i++;
			c = c * 3 + 1;
		}
	}
	return i;
}

int main() {
	int n;
	cin >> n;
	cout << function(n) << endl;
	return 0;
}