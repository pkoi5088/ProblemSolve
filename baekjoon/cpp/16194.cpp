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
	vector<int> card, dp;
	int N;
	cin >> N;
	card.resize(N);
	dp.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> card[i];
		dp[i] = card[i];
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			dp[i] = min(dp[i], dp[j] + card[i - 1 - j]);
		}
	}
	cout << dp[N - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
