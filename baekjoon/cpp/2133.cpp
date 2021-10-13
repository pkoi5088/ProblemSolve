#include <iostream>
#include <string>

using namespace std;

int solve() {
	int N;
	cin >> N;
	if (N % 2 == 1) {
		return 0;
	}

	int dp[31] = { 0, };
	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= N; i += 2) {
		int R = 0;
		if (i - 2 >= 0) {
			R += dp[i - 2] * 3;
		}
		for (int j = i - 4; j >= 0; j -= 2) {
			R += dp[j] * 2;
		}
		dp[i] = R;
	}
	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve();
	return 0;
}