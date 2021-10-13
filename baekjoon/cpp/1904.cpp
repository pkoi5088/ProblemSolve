#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int *board = new int[N + 1];
	board[0] = 1;
	board[1] = 1;
	for (int i = 2; i <= N; i++) {
		board[i] = (board[i - 1] + board[i - 2]) % 15746;
	}
	cout << board[N];
	delete board;
	return 0;
}