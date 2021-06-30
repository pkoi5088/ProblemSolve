#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF -100000001
#define MAX 100000
#define endl '\n'

using namespace std;

int dp[2][MAX], nums[MAX];
int N;

void solve() {
	int result = INF;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}
	for (int i = 0; i < N; ++i) {
		dp[0][i] = dp[1][i] = INF;
	}

	if (N == 1) {
		cout << nums[0];
		return;
	}
	dp[0][0] = nums[0];
	dp[1][0] = max(nums[0], 0);
	for (int i = 1; i < N; ++i) {
		dp[0][i] = max(dp[0][i - 1] + nums[i], nums[i]);
		dp[1][i] = max(dp[1][i - 1] + nums[i], dp[0][i - 1]);
		result = max(result, max(dp[0][i], dp[1][i]));
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
