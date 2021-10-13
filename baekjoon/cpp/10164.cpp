#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int board[15][15] = { 0 };
int N, M, K;

int NtoM(int S, int E) {
	int sx = (S - 1) / M, sy = (S - 1) % M;
	int ex = (E - 1) / M, ey = (E - 1) % M;
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			board[i][j] = 1;
		}
	}
	for (int i = sx+1; i <= ex; i++) {
		for (int j = sy+1; j <= ey; j++) {
			board[i][j] = board[i - 1][j] + board[i][j - 1];
		}
	}
	return board[ex][ey];
}

int solve() {
	cin >> N >> M >> K;
	if (K == 0) {
		return NtoM(1, N * M);
	}
	else {
		return NtoM(1, K) * NtoM(K, N * M);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}