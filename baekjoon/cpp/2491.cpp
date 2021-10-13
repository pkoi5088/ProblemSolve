#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 100000
#define endl '\n'

using namespace std;

int nums[MAX];
int dp[2][MAX] = { 0 };

void solve() {
	int N, result = 1;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> nums[i];
	dp[0][0] = dp[1][0] = 1;
	
	for (int i = 1; i < N; ++i) {
		if (nums[i - 1] <= nums[i]) {
			dp[0][i] = dp[0][i - 1] + 1;
			result = max(result, dp[0][i]);
		}
		else {
			dp[0][i] = 1;
		}
		if (nums[i - 1] >= nums[i]) {
			dp[1][i] = dp[1][i - 1] + 1;
			result = max(result, dp[1][i]);
		}
		else {
			dp[1][i] = 1;
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
