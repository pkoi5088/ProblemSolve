#include <iostream>
#define endl '\n'
#define MAX 2000

using namespace std;

/*
	https://www.acmicpc.net/problem/21922
*/

//first: 종류,second: 방향, 상하좌우
int nextDirTable[4][4] = {
	{0,1,3,2},
	{1,0,2,3},
	{3,2,1,0},
	{2,3,0,1}
};
bool visit[MAX][MAX][4] = { false };
int arr[MAX][MAX];
int N, M, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void wind(int x, int y, int dir) {
	int nx = x + dx[dir], ny = y + dy[dir], nDir = dir;
	visit[x][y][dir] = true;
	while (true) {
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			return;
		if (nx == x && ny == y)
			return;
		if (visit[nx][ny][nDir])
			return;

		visit[nx][ny][nDir] = true;
		if (arr[nx][ny] != 9 && arr[nx][ny] != 0) {
			nDir = nextDirTable[arr[nx][ny] - 1][nDir];
		}
		nx += dx[nDir], ny += dy[nDir];
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 9) {
				wind(i, j, 0);
				wind(i, j, 1);
				wind(i, j, 2);
				wind(i, j, 3);
			}
		}
	}
	
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int k = 0; k < 4; ++k) {
				if (visit[i][j][k]) {
					ret += 1;
					break;
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