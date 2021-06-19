#include <iostream>
#include <algorithm>

using namespace std;

int board[10] = { 0 };

int main() {
	int N;
	cin >> N;

	if (N == 0)
		board[0]++;

	while (N != 0) {
		board[N % 10]++;
		N = N / 10;
	}

	int n = 0;
	for (int i = 0; i < 10; i++) {
		if (i != 9 && i != 6)
			n = max(n, board[i]);
	}

	cout << max(n, (board[6] + board[9] + 1) / 2);
	return 0;
}