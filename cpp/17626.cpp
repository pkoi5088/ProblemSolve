#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#define MAX 50001
#define endl '\n'

using namespace std;

int dp[MAX] = { 0 };

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}
	for (int i = 1; i <= int(sqrt(n)); ++i) {
		dp[i * i] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= int(sqrt(i)); ++j) {
			dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]);
		}
	}
	cout << dp[n];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
