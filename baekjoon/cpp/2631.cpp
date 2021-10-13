#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int dp[200];
int M[200];

int solve() {
	int N, result = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M[i];
		dp[i] = -1;
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		int t = 1;
		for (int j = 0; j < i; j++) {
			if (M[i] > M[j]) {
				t = max(t, dp[j] + 1);
			}
		}
		dp[i] = t;
		result = max(result, t);
	}
	return N - result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}