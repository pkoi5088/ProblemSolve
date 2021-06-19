#include <iostream>
#include <string.h>

using namespace std;

int map[502][502], dp[502][502];
int M, N;
int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };

int dfs(int a, int b) {
	if (dp[a][b] != -1)
		return dp[a][b];
	if (a == N && b == M)
		return 1;

	dp[a][b] = 0;
	for (int i = 0; i < 4; i++) {
		int N_x = a + dx[i];
		int N_y = b + dy[i];
		if (map[N_x][N_y] < map[a][b])
			dp[a][b] += dfs(N_x, N_y);
	}
	return dp[a][b];
}

int main() {
	cin >> N >> M;

	for (int i = 0; i <= 501; i++) {
		memset(dp[i], -1, sizeof(dp[i]));
		memset(map[i], 10001, sizeof(map[i]));
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	}

	cout << dfs(1, 1);
	return 0;
}