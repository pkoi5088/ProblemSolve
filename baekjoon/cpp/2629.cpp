#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 40001
#define endl '\n'

using namespace std;

void solve() {
	vector<vector<bool>> dp;
	vector<int> weight;
	int N, M;
	cin >> N;
	weight.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> weight[i];
	dp.resize(N);
	for (int i = 0; i < N; ++i) {
		dp[i].resize(MAX, false);
	}

	dp[0][weight[0]] = true;
	for (int i = 1; i < N; ++i) {
		int now = weight[i];
		dp[i][now] = true;
		for (int j = 1; j < MAX; ++j) {
			if (dp[i - 1][j]) {
				dp[i][j] = true;
				if (now - j >= 0) {
					dp[i][now - j] = true;
				}
				if (j-now >= 0) {
					dp[i][j - now] = true;
				}
				if (now + j < MAX) {
					dp[i][now + j] = true;
				}
			}
		}
	}

	cin >> M;
	while (M--) {
		int x;
		cin >> x;
		cout << (dp[N - 1][x] ? "Y " : "N ");
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
