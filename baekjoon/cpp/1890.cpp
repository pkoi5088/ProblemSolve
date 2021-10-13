#include <iostream>

using namespace std;

long solve() {
	int N;
	cin >> N;
	int map[100][100] = { 0 };
	long dp[100][100] = { 0 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] > 0 && map[i][j] != 0) {
				int nx = i + map[i][j], ny = j + map[i][j];
				if (nx < N) {
					dp[nx][j] += dp[i][j];
				}
				if (ny < N) {
					dp[i][ny] += dp[i][j];
				}
			}
		}
	}

	return dp[N-1][N-1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve();
	return 0;
}