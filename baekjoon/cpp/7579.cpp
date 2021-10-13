#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 100000
#define MAX 10001
#define endl '\n'

using namespace std;

vector<vector<int>> dp;
vector<int> memory, cost;

void solve() {
	int N, M, result = INF;
	cin >> N >> M;
	dp.resize(N + 1);
	memory.resize(N);
	cost.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> memory[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> cost[i];
	}
	for (int i = 0; i < N+1; ++i) {
		dp[i].resize(MAX, 0);
	}

	for (int i = 1; i < N + 1; ++i) {
		for (int j = 0; j < MAX; ++j) {
			if (cost[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j - cost[i - 1]] + memory[i - 1], dp[i - 1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			if (dp[i][j] >= M) {
				result = min(result, j);
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
