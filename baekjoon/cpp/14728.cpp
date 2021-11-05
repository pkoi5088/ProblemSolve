#include <iostream>
#include <cstring>
#define MAX_N 101
#define MAX_T 10001
#define endl '\n'

using namespace std;

int dp[MAX_N][MAX_T], st[MAX_N], score[MAX_N];
int N, T;

void solve() {
	memset(dp, 0, sizeof(dp));
	cin >> N >> T;
	for (int i = 1; i <= N; ++i) {
		cin >> st[i] >> score[i];
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= T; ++j) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (j - st[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - st[i]] + score[i]);;
		}
	}
	cout << dp[N][T];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
