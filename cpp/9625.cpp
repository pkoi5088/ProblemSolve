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
	//dp[0]은 A의 개수, dp[1]은 B의 개수
	vector<int> dp[2];
	int K;
	cin >> K;
	dp[0].resize(K + 1, 0);
	dp[1].resize(K + 1, 0);
	dp[0][0] = 1;
	for (int i = 1; i < K + 1; ++i) {
		dp[0][i] = dp[1][i - 1];
		dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
	}
	cout << dp[0][K] << ' ' << dp[1][K];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
