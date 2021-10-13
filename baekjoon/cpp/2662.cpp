#include <iostream>
#include <cstring>
#include <vector>
#define MAX_N 301
#define MAX_M 21
#define endl '\n'

using namespace std;

int dp[MAX_N][MAX_M], value[MAX_N], profit[MAX_N][MAX_M] = { 0, }, parent[MAX_N][MAX_M] = { 0, };
int N, M, result[MAX_N];

int getDP(int n, int m) {
	if (n <= 0 || m <= 0) return 0;
	int& ret = dp[n][m];
	if (ret != -1) return ret;

	ret = profit[n][m];
	parent[n][m] = n;
	for (int cost = 0; cost <= n; ++cost) {
		if (ret < getDP(n - cost, m - 1) + profit[cost][m]) {
			ret = getDP(n - cost, m - 1) + profit[cost][m];
			parent[n][m] = cost;
		}
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> value[i];
		for (int j = 1; j <= M; ++j)
			cin >> profit[i][j];
	}
	cout << getDP(N, M) << endl;

	vector<int> result;
	int idx = M, restMoney = N;
	while (idx > 0) {
		result.push_back(parent[restMoney][idx]);
		restMoney -= parent[restMoney][idx];
		idx -= 1;
	}
	for (int i = result.size() - 1; i >= 0; --i)
		cout << result[i] << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
