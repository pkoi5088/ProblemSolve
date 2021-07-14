#include <iostream>
#include <cstring>
#define MAX 1001
#define endl '\n'
#define MOD 1000000003

using namespace std;

int dp[MAX][MAX];

int getDP(int n, int k) {
	if (n < 0) return 0;
	else if (n == 0 || k > n / 2 + 1) return dp[n][k] = 0;
	else if (dp[n][k] != -1) return dp[n][k];
	else if (k == 0) return dp[n][k] = 1;
	else if (k == 1) return dp[n][k] = n;
	return dp[n][k] = (getDP(n - 1, k) + getDP(n - 2, k - 1)) % MOD;
}

void solve() {
	int N, K;
	cin >> N >> K;
	memset(dp, -1, sizeof(dp));
	dp[1][1] = 1;
	cout << (getDP(N - 1, K) + getDP(N - 3, K - 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
