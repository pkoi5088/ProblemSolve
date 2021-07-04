#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> M;
int N, cnt = 0;

//0 가로, 1 세로, 2 대각선
void dfs(int x, int y, int state) {
	if (x == N && y == N) {
		cnt++;
	}
	else {
		if (state == 0) {
			if (M[x][y + 1] == 0)
				dfs(x, y + 1, 0);
			if (M[x][y + 1] == 0 && M[x + 1][y] == 0 && M[x + 1][y + 1] == 0)
				dfs(x + 1, y + 1, 2);
		}
		else if (state == 1) {
			if (M[x + 1][y] == 0)
				dfs(x + 1, y, 1);
			if (M[x][y + 1] == 0 && M[x + 1][y] == 0 && M[x + 1][y + 1] == 0)
				dfs(x + 1, y + 1, 2);
		}
		else {
			if (M[x][y + 1] == 0)
				dfs(x, y + 1, 0);
			if (M[x + 1][y] == 0)
				dfs(x + 1, y, 1);
			if (M[x][y + 1] == 0 && M[x + 1][y] == 0 && M[x + 1][y + 1] == 0)
				dfs(x + 1, y + 1, 2);
		}
	}
}

int solve() {
	cin >> N;
	M.resize(N + 2);
	for (int i = 0; i < N + 2; i++) {
		M[i].resize(N + 2, 1);
	}
	for (int i = 1; i < N + 1; i++) {
		for (int j = 1; j < N + 1; j++) {
			cin >> M[i][j];
		}
	}
	dfs(1, 2, 0);
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve();
	return 0;
}