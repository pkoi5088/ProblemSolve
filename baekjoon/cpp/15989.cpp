#include <iostream>
#include <cstring>
#define MAX 10001
#define endl '\n'

using namespace std;

int dp[MAX][3];

int getDP(int n, int last) {
	if (n <= 0) return 0;
	if (dp[n][last] != -1) return dp[n][last];

	int& ret = dp[n][last];
	if (last == 0) ret = 1;
	else if (last == 1) ret = getDP(n - 2, 0) + getDP(n - 2, 1);
	else if (last == 2) ret = getDP(n - 3, 0) + getDP(n - 3, 1) + getDP(n - 3, 2);
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	dp[2][1] = dp[3][2] = 1;
	dp[1][1] = dp[1][2] = dp[2][2] = 0;
	cout << getDP(n, 0) + getDP(n, 1) + getDP(n, 2) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
