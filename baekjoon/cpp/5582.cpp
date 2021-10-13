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
	string s1, s2;
	cin >> s1 >> s2;
	int N = s1.size(), M = s2.size(), result = 0;
	dp.resize(N + 1);
	for (int i = 0; i < N + 1; ++i) {
		dp[i].resize(M + 1, 0);
	}

	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1; j < M + 1; ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				result = max(result, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
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
