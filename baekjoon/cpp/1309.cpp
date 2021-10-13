#include <iostream>

using namespace std;

int solve() {
	int N;
	cin >> N;
	int dp[100001][2] = { 0 };
	dp[1][0] = 1;
	dp[1][1] = 2;
	for (int i = 2; i <= N; i++) {
		dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
		dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1]) % 9901;
	}
	return (dp[N][0] + dp[N][1]) % 9901;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve();
	return 0;
}