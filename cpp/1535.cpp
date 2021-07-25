#include <iostream>
#define MAX_N 21
#define MAX_H 101
#define endl '\n'

using namespace std;


void solve() {
	int cost[MAX_N] = { 0, }, happy[MAX_N] = { 0, };
	int dp[MAX_N][MAX_H] = { 0, };
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> cost[i];
	for (int i = 1; i <= N; ++i)
		cin >> happy[i];

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j < MAX_H; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j - cost[i] > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + happy[i]);
		}
	}
	cout << dp[N][MAX_H - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
