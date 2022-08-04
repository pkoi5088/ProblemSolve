#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	https://www.acmicpc.net/problem/14500
*/

vector<vector<int>> board;
vector<vector<bool>> visit;
int N, M, result = -1, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void dfs(int x, int y, int total, int depth) {
	if (depth == 4) {
		result = max(result, total);
	}
	else {
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				dfs(nx, ny, total + board[nx][ny], depth + 1);
				visit[nx][ny] = false;
			}
		}
	}
}

void solve() {
	cin >> N >> M;
	board.resize(N);
	visit.resize(N);
	for (int i = 0; i < N; i++) {
		board[i].resize(M);
		visit[i].resize(M, false);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = true;
			dfs(i, j, board[i][j], 1);
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//ㅗ,ㅜ
			if (i < N - 1 && j < M - 2) {
				int t1 = board[i][j + 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i + 1][j + 2],
					t2 = board[i + 1][j + 1] + board[i][j] + board[i][j + 1] + board[i][j + 2];
				result = max(result, max(t1, t2));
			}
			//ㅓ,ㅏ
			if (i < N - 2 && j < M - 1) {
				int t1 = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1],
					t2 = board[i + 1][j] + board[i + 1][j + 1] + board[i + 2][j + 1] + board[i][j + 1];
				result = max(result, max(t1, t2));
			}
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
