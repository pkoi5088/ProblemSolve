#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int map[MAX];
int dp[MAX] = { -1 };

int main() {
	int n;
	int max_ = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> map[i];
	dp[1] = map[1];
	max_ = dp[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + map[i], map[i]);
		max_ = max(dp[i], max_);
	}

	cout << max_;
	return 0;
}