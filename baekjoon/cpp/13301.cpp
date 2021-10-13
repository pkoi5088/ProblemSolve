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
	vector<long long> dp;
	int N;
	cin >> N;
	dp.resize(N + 1, 0);
	dp[1] = 1;
	for (int i = 2; i < N + 1; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << 2 * dp[N] + 2 * (dp[N] + dp[N - 1]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
