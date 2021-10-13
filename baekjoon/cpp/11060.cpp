#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 1001
#define endl '\n'

using namespace std;

void solve() {
	vector<int> v, dp;
	int N;
	cin >> N;
	v.resize(N);
	dp.resize(N, INF);
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= v[i]; ++j) {
			if (i + j < N)
				dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}
	cout << (dp[N - 1] == INF ? -1 : dp[N - 1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
