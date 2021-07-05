#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int* board = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}
	int t = board[N - 1], cnt = 1;
	while (N--) {
		if (board[N - 1] > t) {
			cnt++;
			t = board[N - 1];
		}
	}
	cout << cnt;
	return 0;
}