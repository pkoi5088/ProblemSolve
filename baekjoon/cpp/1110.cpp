#include <iostream>

using namespace std;

int main() {
	int N, a, b, tmp, cnt = 0;
	cin >> N;

	a = N / 10;
	b = N % 10;
	tmp = b * 10 + (a + b) % 10;
	cnt++;

	while (N != tmp) {
		a = tmp / 10;
		b = tmp % 10;
		tmp = b * 10 + (a + b) % 10;
		cnt++;
	}
	cout << cnt;
	return 0;
}