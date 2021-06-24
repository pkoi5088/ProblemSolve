#include <iostream>

using namespace std;

long long int f(int n) {
	long long int a = 0, b = 1, tmp;

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	n -= 1;

	while (n--) {
		tmp = a + b;
		a = b;
		b = tmp;
	}
	return b;
}

int main() {
	int a, b, n, tmp;
	cin >> n;

	cout << f(n);
	return 0;
}