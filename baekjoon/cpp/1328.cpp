#include <iostream>
#include <cstring>
#define MAX 101
#define MOD 1000000007
#define endl '\n'

using namespace std;

long long dp[MAX][MAX][MAX];

long long getDP(int n, int l, int r) {
	if (dp[n][l][r] != -1) return dp[n][l][r];
	else if (n == 0 || l == 0 || r == 0) return dp[n][l][r] = 0;
	else if (l == 1 && r == n || l == n && r == 1) return dp[n][l][r] = 1;
	dp[n][l][r] = getDP(n - 1, l, r) * (n - 2) + getDP(n - 1, l - 1, r) + getDP(n - 1, l, r - 1);
	dp[n][l][r] %= MOD;
	return dp[n][l][r];
}

void solve() {
	int N, L, R;
	memset(dp, -1, sizeof(dp));
	dp[1][1][1] = 1;
	cin >> N >> L >> R;
	cout << getDP(N, L, R);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
