#include <iostream>

using namespace std;

int main() {
	int N, kg3 = 0, kg5 = 0;
	bool flag = false;
	cin >> N;
	while (N != 1 && N != 2) {
		if (N == 0) {
			flag = true;
			break;
		}
		if (N % 5 == 0) {
			kg5 += N / 5;
			flag = true;
			break;
		}
		kg3++;
		N -= 3;
	}
	if (flag)
		cout << kg3 + kg5;
	else
		cout << -1;
	return 0;
}