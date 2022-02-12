#include <iostream>
#include <cstring>
#include <string>
#define MAX 1000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/9251
*/

string t, p;
int dp[MAX][MAX];

void solve() {
	memset(dp, 0, sizeof(dp));
	cin >> t >> p;
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < p.size(); j++) {
			if (t[i] == p[j]) {
				if (i == 0 || j == 0) {
					dp[i][j] = 1;
				}
				else {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
			else {
				dp[i][j] = 0;
				if (i == 0 && j == 0) continue;
				else if (i == 0)
					dp[i][j] = dp[i][j - 1];
				else if (j == 0)
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[t.size() - 1][p.size() - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}