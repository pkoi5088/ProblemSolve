#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/20057
*/

vector<vector<int>> arr;
int ret = 0, N;
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
pair<pair<int, int>, double> delta[4][10] = {
	{{{-2,0},0.05},{{-1,1},0.1},{{-1,-1},0.1},{{0,-2},0.02},{{0,-1},0.07},{{0,1},0.07},{{0,2},0.02},{{1,-1},0.01},{{1,1},0.01},{{-1,0},0.0}},
	{{{0,2},0.05},{{-1,1},0.1},{{1,1},0.1},{{2,0},0.02},{{1,0},0.07},{{-1,0},0.07},{{-2,0},0.02},{{-1,-1},0.01},{{1,-1},0.01},{{0,1},0.0}},
	{{{2,0},0.05},{{1,1},0.1},{{1,-1},0.1},{{0,-2},0.02},{{0,-1},0.07},{{0,1},0.07},{{0,2},0.02},{{-1,-1},0.01},{{-1,1},0.01},{{1,0},0.0}},
	{{{0,-2},0.05},{{-1,-1},0.1},{{1,-1},0.1},{{2,0},0.02},{{1,0},0.07},{{-1,0},0.07},{{-2,0},0.02},{{-1,1},0.01},{{1,1},0.01},{{0,-1},0.0}}
};

void solve() {
	cin >> N;
	arr.resize(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}

	int x = N / 2, y = N / 2;
	int dir = 3, move = 1, rotate = 2;
	int restmove = 1;
	while (true) {
		x += dx[dir], y += dy[dir];
		if (y == -1)
			break;

		//바람처리
		int sand = 0;
		for (int k = 0; k < 10; ++k) {
			int nx = x + delta[dir][k].first.first, ny = y + delta[dir][k].first.second;
			double ratio = delta[dir][k].second;
			if (k != 9) {
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
					ret += (int)(arr[x][y] * ratio);
				}
				else {
					arr[nx][ny] += (int)(arr[x][y] * ratio);
				}
				sand += (int)(arr[x][y] * ratio);
			}
			else {
				if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
					ret += (int)(arr[x][y] - sand);
				}
				else {
					arr[nx][ny] += (int)(arr[x][y] - sand);
				}
			}
		}

		//방향전환
		restmove -= 1;
		if (restmove == 0) {
			dir = (dir + 3) % 4;
			rotate -= 1;
			if (rotate == 0) {
				move += 1;
				rotate = 2;
			}
			restmove = move;
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