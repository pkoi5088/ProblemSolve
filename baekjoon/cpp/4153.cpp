#include <iostream>

using namespace std;

int main() {
	int a, b, c, tmp;
	while (true) {
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;
		if (a > b) {
			tmp = b;
			b = a;
			a = tmp;
		}
		if (b > c) {
			tmp = c;
			c = b;
			b = tmp;
		}
		if (c*c == a * a + b * b)
			cout << "right\n";
		else
			cout << "wrong\n";
	}
	return 0;
}