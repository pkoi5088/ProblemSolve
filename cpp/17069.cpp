#include <iostream>
#include <cstring>
#define MAX 32
#define endl '\n'

using namespace std;

//0: 가로, 1:세로, 2: 대각선
long long dp[MAX][MAX][3];
int board[MAX][MAX];
int N;

long long getDP(int x,int y,int type) {
	if (dp[x][y][type] != -1) return dp[x][y][type];

	long long& ret = dp[x][y][type];
	//기저사례
	if (x == N - 1 && y == N - 1) return ret = 1;

	//가로
	int nx, ny;
	ret = 0;
	if (type != 1) {
		ny = y + 1;
		if (ny < N && board[x][ny] != 1)
			ret += getDP(x, ny, 0);
	}

	//세로
	if (type != 0) {
		nx = x + 1;
		if (nx < N && board[nx][y] != 1)
			ret += getDP(nx, y, 1);
	}

	//대각선
	nx = x + 1, ny = y + 1;
	if (nx < N && ny < N && board[nx][ny] != 1 && board[nx-1][ny] != 1 && board[nx][ny-1] != 1)
		ret += getDP(nx, ny, 2);
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> board[i][j];
		}
	}
	cout << getDP(0, 1, 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
