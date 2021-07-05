#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

int board[500][500] = { 0 };
int N, M, B;

int getCost(int standard) {
	int low = 0, high = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] < standard) {
				low += standard - board[i][j];
			}
			else if (board[i][j] > standard) {
				high += board[i][j] - standard;
			}
		}
	}
	if (low > high + B)
		return -1;
	return high * 2 + low;
}

void solve() {
	int low = 257, high = -1;
	int time = 2000000000, height = -1;
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			low = min(low, board[i][j]);
			high = max(high, board[i][j]);
		}
	}

	for (int standard = low; standard <= high; standard++) {
		int cost = getCost(standard);
		if (cost == -1)
			continue;
		if (time > cost) {
			time = cost;
			height = standard;
		}
		else if (time == cost && height < standard) {
			height = standard;
		}
	}
	cout << time << ' ' << height;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
