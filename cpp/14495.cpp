#include <iostream>
#include <cstring>
#define MAX 117
#define endl '\n'

using namespace std;

long long dp[MAX];

long long getDP(int n) {
	if (dp[n] != -1) return dp[n];
	return dp[n] = getDP(n - 1) + getDP(n - 3);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	dp[1] = dp[2] = dp[3] = 1;
	int n;
	cin >> n;
	cout << getDP(n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
