#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> backup, map, visit;
int N, M, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };

int count() {
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				result += 1;
			}
			visit[i][j] = 0;
		}
	}
	return result;
}

void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 2) {
				q.push({ i,j });
				visit[i][j] = 1;
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0 && visit[nx][ny] == 0) {
				q.push({ nx,ny });
				visit[nx][ny] = 1;
				map[nx][ny] = 2;
			}
		}
	}
}

int solve() {
	int result = -1;
	cin >> N >> M;
	backup.resize(N);
	map.resize(N);
	visit.resize(N);
	for (int i = 0; i < N; i++) {
		backup[i].resize(M);
		map[i].resize(M);
		visit[i].resize(M, 0);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> backup[i][j];
		}
	}
	map = backup;
	for (int i = 0; i < N * M - 2; i++) {
		int ix = i / M, iy = i % M;
		if (map[ix][iy] != 0)
			continue;
		map[ix][iy] = 1;
		for (int j = i + 1; j < N * M - 1; j++) {
			int jx = j / M, jy = j % M;
			if (map[jx][jy] != 0)
				continue;
			map[jx][jy] = 1;
			for (int k = j + 1; k < N * M; k++) {
				int kx = k / M, ky = k % M;
				if (map[kx][ky] != 0) {
					continue;
				}
				else {
					map[kx][ky] = 1;
					bfs();
					result = max(result, count());
					//reset
					map = backup;
					map[ix][iy] = map[jx][jy] = 1;
				}
			}
			map[jx][jy] = 0;
		}
		map[ix][iy] = 0;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}