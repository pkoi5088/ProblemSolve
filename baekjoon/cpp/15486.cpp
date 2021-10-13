#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#define MAX 1500001
#define endl '\n'

using namespace std;

pair<int, int> consulting[MAX];
int dp[MAX] = { 0 };
int N;

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> consulting[i].first >> consulting[i].second;
	}
	for (int i = 0; i < N; ++i) {
		int next = i + consulting[i].first;
		if (next <= N) {
			dp[next] = max(dp[next], dp[i] + consulting[i].second);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]);
	}
	cout << dp[N];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
