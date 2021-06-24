#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#define MAX 65
#define endl '\n'

using namespace std;

long long dp[10][MAX];

void init() {
	for (int i = 0; i < 10; ++i) {
		dp[i][1] = 1;
	}
	for (int i = 2; i < MAX; ++i) {
		dp[9][i] = 1;
		for (int j = 8; j >= 0; --j) {
			dp[j][i] = dp[j + 1][i] + dp[j][i - 1];
		}
	}
}

void solve() {
	int n;
	cin >> n;
	long long result = 0;
	for (int i = 0; i < 10; ++i) {
		result += dp[i][n];
	}
	cout << result << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	init();
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
