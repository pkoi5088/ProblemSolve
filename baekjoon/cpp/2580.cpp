#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int board[9][9] = { 0 };
vector<pair<int, int>> zero;

int checkLoc(int x, int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == num || board[i][y] == num)
			return 0;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[3 * (x / 3) + i][3 * (y / 3) + j] == num)
				return 0;
		}
	}
	return 1;
}

void dfs(int index) {
	if (index == zero.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	int x = zero[index].first, y = zero[index].second;
	vector<int> able;
	for (int i = 1; i < 10; i++) {
		if (checkLoc(x, y, i)) {
			able.push_back(i);
		}
	}
	for (int i = 0; i < able.size(); i++) {
		board[x][y] = able[i];
		dfs(index + 1);
		board[x][y] = 0;
	}
}

void solve() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				zero.push_back({ i,j });
		}
	}
	dfs(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}