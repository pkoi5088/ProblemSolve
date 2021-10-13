#include <iostream>
#define MAX 1001
#define endl '\n'

using namespace std;

void solve() {
	int dp[MAX] = { 0, }, N;
	cin >> N;
	dp[1] = dp[3] = 0;
	dp[2] = dp[4] = dp[5] = 1;
	for (int i = 6; i <= N; ++i) {
		if (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0)
			dp[i] = 1;
	}
	cout << (dp[N] == 1 ? "SK" : "CY");
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
