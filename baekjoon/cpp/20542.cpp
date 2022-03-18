#include <iostream>
#include <string>
#include <vector>
#define endl '\n'

using namespace std;

vector<vector<int>> dp;
string mark, answer;
int N, M;

void solve() {
	cin >> N >> M >> mark >> answer;
	dp.resize(N + 1);
	for (int i = 0; i < N + 1; ++i)
		dp[i].resize(M + 1, 0);
	for (int i = 0; i < N + 1; ++i)
		dp[i][0] = i;
	for (int i = 0; i < M + 1; ++i)
		dp[0][i] = i;

	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1; j < M + 1; ++j) {
			if (mark[i - 1] == answer[j - 1]||(mark[i - 1] == 'i' && (answer[j - 1] == 'j' || answer[j - 1] == 'l'))||(mark[i - 1] == 'v' && answer[j - 1] == 'w')) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1];
				dp[i][j] = min(dp[i][j], dp[i - 1][j]);
				dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				dp[i][j] += 1;
			}
		}
	}
	cout << dp[N][M];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}