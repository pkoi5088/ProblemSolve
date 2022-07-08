#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 200
#define MAX_K 31

using namespace std;

/*
	https://www.acmicpc.net/problem/1600
*/

int W, H, K;
int arr[MAX][MAX], dist[MAX][MAX][MAX_K];
int dx[12] = { -1,1,0,0,-2,-2,-1,-1,1,1,2,2 }, dy[12] = { 0,0,-1,1,-1,1,-2,2,-2,2,-1,1 };

int max(int a, int b) {
	if (a == -1) return b;
	else if (b == -1) return a;
	return a < b ? b : a;
}

void solve() {
	cin >> K >> W >> H;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cin >> arr[i][j];
			for (int k = 0; k <= K; ++k)
				dist[i][j][k] = -1;
		}
	}

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{0,0} });
	dist[0][0][0] = 0;
	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second, d = q.front().second.first, jump = q.front().second.second;
		q.pop();
		if (x == H - 1 && y == W - 1) {
			break;
		}

		//일반 이동
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W || arr[nx][ny] == 1 || dist[nx][ny][jump] != -1)
				continue;
			q.push({ {nx,ny},{d + 1,jump} });
			dist[nx][ny][jump] = d + 1;
		}

		//점프
		for (int k = 4; k < 12; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W || arr[nx][ny] == 1 || jump + 1>K || dist[nx][ny][jump + 1] != -1)
				continue;
			q.push({ {nx,ny},{d + 1,jump + 1} });
			dist[nx][ny][jump + 1] = d + 1;
		}
	}

	int ret = -1;
	for (int i = 0; i <= K; ++i) {
		ret = max(ret, dist[H - 1][W - 1][i]);
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