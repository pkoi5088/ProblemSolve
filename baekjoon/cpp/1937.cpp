#include <iostream>

using namespace std;

int map[502][502], dp[502][502];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

int max(int a, int b) {
	return a > b ? a : b;
}

int dfs(int x, int y) {
	//이미 탐색한곳
	if (dp[x][y] != -1) return dp[x][y];

	//단식투쟁
	if (map[x][y] >= map[x - 1][y] && map[x][y] >= map[x + 1][y] && map[x][y] >= map[x][y - 1] && map[x][y] >= map[x][y + 1]) {
		dp[x][y] = 1;
		return dp[x][y];
	}

	int result = -1;
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (map[x][y] < map[nextX][nextY])
			result = max(result, dfs(nextX, nextY) + 1);
	}
	dp[x][y] = result;
	return dp[x][y];
}

int main() {
	int N, R = -1;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i <= N + 1; i++) {
		map[0][i] = map[i][0] = map[N + 1][i] = map[i][N + 1] = -1;
		dp[0][i] = dp[i][0] = dp[N + 1][i] = dp[i][N + 1] = -1;
	}

	for (int i = 1; i <=N ; i++) {
		for (int j = 1; j <= N; j++) {
			R = max(R, dfs(i, j));
		}
	}

	cout << R<<endl;

	return 0;
}