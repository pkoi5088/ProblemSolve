#include <iostream>
#include <algorithm>

using namespace std;

int find(int* board, int size, int answer) {
	int f = 0, b = size - 1;
	int m;
	while (b >= f) {
		m = (b + f) / 2;
		if (board[m] == answer) {
			return 1;
		}
		else if (board[m] > answer) {
			b = m - 1;
		}
		else {
			f = m + 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cin >> M;
	int* map = new int[M];
	for (int i = 0; i < M; i++) {
		cin >> map[i];
	}

	sort(arr, arr + N);
	for (int i = 0; i < M; i++) {
		cout << find(arr, N, map[i])<<"\n";
	}
	return 0;
}