#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 1002
#define INF 1003
#define endl '\n'

using namespace std;

int dp[MAX];

void solve() {
	int S;
	cin >> S;
	for (int i = 0; i <= 1000; ++i) {
		dp[i] = INF;
	}
	dp[1] = 0;
	for (int i = 1; i <= 1000; ++i) {
		for (int j = 2; i * j <= 1000; ++j) {
			dp[i * j] = min(dp[i * j], dp[i] + j);
		}
		for (int j = 2; j < 1000; ++j) {
			dp[j] = min(dp[j], dp[j + 1] + 1);
		}
	}
	cout << dp[S];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
