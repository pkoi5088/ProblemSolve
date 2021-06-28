#include <iostream>

using namespace std;

int dp[10][1001] = { 0 };

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < 10; i++) {
		dp[i][1] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[j][i] += dp[k][i - 1];
				dp[j][i] %= 10007;
			}
		}
	}
	cout << (dp[0][N] + dp[1][N] + dp[2][N] + dp[3][N] + dp[4][N] + dp[5][N] + dp[6][N] + dp[7][N] + dp[8][N] + dp[9][N]) % 10007;
	return 0;
}