#include <iostream>

using namespace std;

void solve() {
	int N, K;
	cin >> N >> K;
	long dp[201][201] = { 0 };
	for (int i = 0; i <= N; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k] % 1000000000;
			}
			dp[i][j] = dp[i][j] % 1000000000;
		}
	}
	cout << dp[K][N];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}