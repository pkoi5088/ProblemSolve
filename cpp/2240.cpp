#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX_TIME 1001
#define MAX_MOVE 31
#define endl '\n'

using namespace std;

int dp[2][MAX_TIME][MAX_MOVE] = { 0 }, tree[MAX_TIME];
int T, W;

void solve() {
	int result = -1;
	cin >> T >> W;
	for (int i = 1; i < T + 1; ++i) {
		cin >> tree[i];
		tree[i] -= 1;
	}
	if (tree[1])
		dp[1][1][1] = 1;
	else
		dp[0][1][0] = 1;

	for (int i = 2; i < T + 1; ++i) {
		for (int j = 0; j < W + 1; ++j) {
			dp[0][i][j] = dp[0][i - 1][j];
			dp[1][i][j] = dp[1][i - 1][j];
			if (j != 0) {
				dp[0][i][j] = max(dp[0][i][j], dp[1][i - 1][j - 1]);
				dp[1][i][j] = max(dp[1][i][j], dp[0][i - 1][j - 1]);
			}
			dp[tree[i]][i][j] += 1;
		}
	}

	for (int i = 0; i < W + 1; ++i) {
		result = max(result, dp[0][T][i]);
		result = max(result, dp[1][T][i]);
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
