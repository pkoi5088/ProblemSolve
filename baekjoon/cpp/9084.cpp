#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	vector<vector<int>> dp;
	vector<int> coin;
	int N, M;
	cin >> N;
	coin.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> coin[i];
	cin >> M;
	dp.resize(N + 1);
	for (int i = 0; i < N + 1; ++i) {
		dp[i].resize(M + 1, 0);
		dp[i][0] = 1;
	}

	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1; j < M + 1; ++j) {
			for (int k = j; k >= 0; k -= coin[i - 1]) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	cout << dp[N][M] << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
