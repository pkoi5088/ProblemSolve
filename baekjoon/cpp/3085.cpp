#include <iostream>
#include <vector>
#include <string>
#define endl '\n'

using namespace std;

int N, ret = -1, dx[2] = { 0,1 }, dy[2] = { 1,0 };
vector<string> board;

void swap(int x, int y, int nx, int ny) {
	char tmp = board[x][y];
	board[x][y] = board[nx][ny];
	board[nx][ny] = tmp;
}

void check() {
	//세로
	int cnt = 1;
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			if (board[j][i] != board[j - 1][i]) {
				ret = max(ret, cnt);
				cnt = 1;
			}
			else
				cnt += 1;
		}
		ret = max(ret, cnt);
		cnt = 1;
	}

	//가로
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j < N; ++j) {
			if (board[i][j] != board[i][j - 1]) {
				ret = max(ret, cnt);
				cnt = 1;
			}
			else
				cnt += 1;
		}
		ret = max(ret, cnt);
		cnt = 1;
	}
}

void solve() {
	cin >> N;
	board.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> board[i];

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			for (int l = 0; l < 2; ++l) {
				int nx = x + dx[l], ny = y + dy[l];
				if (nx >= N || ny >= N) continue;
				if (board[x][y] != board[nx][ny]) {
					swap(x, y, nx, ny);
					check();
					swap(x, y, nx, ny);
				}
			}
		}
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
