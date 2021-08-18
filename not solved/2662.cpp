#include <iostream>
#include <cstring>
#define MAX_N 300
#define MAX_M 20
#define endl '\n'

using namespace std;

int dp[MAX_N][MAX_M], value[MAX_N], profit[MAX_N][MAX_M], parent[MAX_N][MAX_M];
int N, M, result[MAX_N];

int getDP(int n, int m) {
	if (n < 0 || m < 0) return 0;
	int& ret = dp[n][m];
	if (ret != -1) return ret;

	ret = profit[n][m];
	parent[n][m] = n;
	for (int cost = 0; cost < n; ++cost) {
		if (ret < getDP(n - cost - 1, m - 1) + profit[cost][m]) {
			ret = getDP(n - cost - 1, m - 1) + profit[cost][m];
			parent[n][m] = cost;
		}
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	memset(parent, -1, sizeof(parent));

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> value[i];
		for (int j = 0; j < M; ++j)
			cin >> profit[i][j];
	}
	cout << getDP(N - 1, M - 1) << endl;

	int idx = M - 1, idxN = N - 1;
	while (idx >= 0) {
		result[idx] = (parent[idxN][idx] + 1) / value[idxN];
		idxN -= parent[idxN][idx];
		idx--;
	}

	for (idx = 0; idx < M; ++idx)
		cout << result[idx] << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
