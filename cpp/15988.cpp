#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MOD 1000000009
#define endl '\n'

using namespace std;

void solve() {
	vector<unsigned int> dp;
	int N;
	cin >> N;
	dp.resize(N);
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;
	for (int i = 3; i < N; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}
	cout << dp[N - 1] << endl;
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
