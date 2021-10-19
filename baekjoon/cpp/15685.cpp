#include <iostream>
#include <vector>
#define MAX 101
#define endl '\n'

using namespace std;

int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
bool board[MAX][MAX] = { false, };

int nextDir(int dir) {
	return (dir + 1) % 4;
}

void solve() {
	int N, ret = 0;
	cin >> N;
	while (N--) {
		vector<int> dir;
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dir.push_back(d);
		for (int i = 0; i < g; ++i) {
			for (int idx = dir.size() - 1; idx >= 0; --idx) {
				dir.push_back(nextDir(dir[idx]));
			}
		}


		for (int idx = 0; idx < dir.size(); ++idx) {
			int nx = x + dx[dir[idx]], ny = y + dy[dir[idx]];
			board[x][y] = board[nx][ny] = true;
			x = nx, y = ny;
		}
	}

	for (int x = 0; x < MAX - 1; ++x) {
		for (int y = 0; y < MAX - 1; ++y) {
			if (board[x][y] && board[x + 1][y] && board[x][y + 1] && board[x + 1][y + 1])
				ret += 1;
		}
	}
	cout << ret << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
