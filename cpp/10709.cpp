#include <iostream>
#include <string>
#include <cstring>
#define MAX 100
#define endl '\n'

using namespace std;

int dp[MAX][MAX];
string board[MAX];
int H, W;

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> H >> W;
	for (int i = 0; i < H; ++i)
		cin >> board[i];
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (board[i][j] == 'c') {
				dp[i][j] = 0;
			}
			else if (j > 0 && dp[i][j - 1] != -1) {
				dp[i][j] = dp[i][j - 1] + 1;
			}
		}
	}

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
