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

vector<int> v, dp;
int N, result = 1;

void solve() {
	cin >> N;
	v.resize(N);
	dp.resize(N, 1001);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	dp[0] = 1;
	for (int i = 1; i < N; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (v[i] < v[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				result = max(result, dp[i]);
			}
		}
	}
	
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
