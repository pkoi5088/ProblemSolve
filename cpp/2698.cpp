#include <iostream>
#include <cstring>
#define MAX 101
#define endl "\n"

using namespace std;

int dp[MAX][MAX][2];

int getDP(int n, int k, int type) {
	if (n <= 0) return 0;
	if (n <= k) return 0;
	int& ret = dp[n][k][type];
	if (ret != -1) return ret;

	ret = 0;
	if (type) {
		ret = getDP(n - 1, k, 0) + getDP(n - 1, k - 1, 1);
	}
	else {
		ret = getDP(n - 1, k, 0) + getDP(n - 1, k, 1);
	}
	return ret;
}

void solve(){
	memset(dp, -1, sizeof(dp));
	dp[2][0][0] = 2;
	dp[2][1][1] = dp[2][0][1] = 1;
	int n, k;
	cin >> n >> k;
	cout << getDP(n, k, 0) + getDP(n, k, 1) << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}