#include <iostream>
#include <queue>
#define MAX 100
#define endl '\n'

using namespace std;

int board[MAX][MAX], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int N, M, cnt = 0;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1) cnt += 1;
		}
	}

	int ret = 0, retChesse = 0;
	queue<pair<int, int>> q, chesse;
	while (true) {
		if (cnt == 0) break;
		ret += 1;

		bool check[MAX][MAX] = { false, };
		q.push({ 0,0 });
		check[0][0] = true;
		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			if (board[x][y] == 1) {
				chesse.push({ x,y });
			}
			else {
				for (int l = 0; l < 4; ++l) {
					int nx = x + dx[l], ny = y + dy[l];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M || check[nx][ny]) continue;
					q.push({ nx,ny });
					check[nx][ny] = true;
				}
			}
		}

		retChesse = 0;
		while (!chesse.empty()) {
			int x = chesse.front().first, y = chesse.front().second;
			chesse.pop();
			board[x][y] = 0;
			cnt -= 1;
			retChesse += 1;
		}
	}
	cout << ret << endl << retChesse;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
