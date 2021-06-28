#include <iostream>
#include <string>

using namespace std;

int solve() {
	int N;
	cin >> N;
	int* B = new int[N];
	int* dp[2] = { 0,0 };
	dp[0] = new int[N];
	dp[1] = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		dp[0][i] = dp[1][i] = 0;
	}
	for (int i = 0; i < N; i++) {
		int M = 0;
		for (int j = 0; j < i; j++) {
			if (B[i] > B[j]) {
				M = max(M, dp[0][j]);
			}
		}
		dp[0][i] = M + 1;
	}
	for (int i = N - 1; i >= 0; i--) {
		int M = 0;
		for (int j = N-1; j > i; j--) {
			if (B[i] > B[j]) {
				M = max(M, dp[1][j]);
			}
		}
		dp[1][i] = M + 1;
	}
	int result = -1;
	for (int i = 0; i < N; i++) {
		result = max(result, dp[0][i] + dp[1][i]);
	}
	return result - 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve();
	return 0;
}