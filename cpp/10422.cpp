#include <iostream>
#include <cstring>
#define MAX 5001
#define MOD 1000000007
#define endl '\n'

using namespace std;

long long dp[MAX];

long long getDP(int n) {
	if (dp[n] != -1) return dp[n];
	dp[n] = 0;
	for (int i = 2; i <= n; i += 2) {
		dp[n] += getDP(i-2) * getDP(n - i);
		dp[n] %= MOD;
	}
	return dp[n];
}

void solve() {
	int T, L;
	cin >> T;
	memset(dp, -1, sizeof(dp));
	dp[0] = dp[2] = 1;
	
	while (T--) {
		cin >> L;
		if (L % 2) cout << 0 << endl;
		else {
			cout << getDP(L) << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
