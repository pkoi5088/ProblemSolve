#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/14502
*/

int N, M;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

int getSafe(vector<vector<int>> arr, queue<pair<int, int>> q) {
	int ret = 0;

	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] != 0) continue;
			q.push({ nx,ny });
			arr[nx][ny] = 2;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 0) ret += 1;
		}
	}
	return ret;
}

void solve() {
	cin >> N >> M;
	vector<vector<int>> arr(N, vector<int>(M));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) q.push({ i,j });
		}
	}

	int ret = 0;
	for (int i = 0; i < N * M - 2; ++i) {
		for (int j = i + 1; j < N * M - 1; ++j) {
			for (int k = j + 1; k < N * M; ++k) {
				int ix = i / M, iy = i % M;
				int jx = j / M, jy = j % M;
				int kx = k / M, ky = k % M;
				if (arr[ix][iy] != 0 || arr[jx][jy] != 0 || arr[kx][ky] != 0) continue;
				arr[ix][iy] = arr[jx][jy] = arr[kx][ky] = 1;
				ret = max(ret, getSafe(arr, q));
				arr[ix][iy] = arr[jx][jy] = arr[kx][ky] = 0;
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