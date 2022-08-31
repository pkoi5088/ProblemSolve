#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 4

using namespace std;

/*
	https://www.acmicpc.net/problem/19236
*/

int ret = 0;
int dx[8] = { -1,-1,0,1,1,1,0,-1 }, dy[8] = { 0,-1,-1,-1,0,1,1,1 };

void swap(vector<vector<pair<int, int>>>& arr, int x1, int y1, int x2, int y2) {
	pair<int, int> tmp = arr[x1][y1];
	arr[x1][y1] = arr[x2][y2];
	arr[x2][y2] = tmp;
}

void fishMoving(vector<vector<pair<int, int>>>& arr, int sharkX, int sharkY) {
	for (int i = 1; i <= 16; ++i) {
		int x = -1, y = -1;
		for (int nx = 0; nx < MAX; ++nx) {
			for (int ny = 0; ny < MAX; ++ny) {
				if (arr[nx][ny].first == i) {
					x = nx, y = ny;
				}
			}
		}

		if (x == -1) continue;

		int cnt = 0;
		while (cnt < 8) {
			int nx = x + dx[arr[x][y].second], ny = y + dy[arr[x][y].second];
			if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX || (sharkX == nx && sharkY == ny)) {
				arr[x][y].second += 1;
				arr[x][y].second %= 8;
				cnt += 1;
				continue;
			}
			swap(arr, x, y, nx, ny);
			break;
		}
		if (cnt == 8) {
			arr[x][y].second += 7;
			arr[x][y].second %= 8;
		}
	}
}

//상어의 위치, 방향, 여태까지 먹은 번호의 합
void search(vector<vector<pair<int, int>>> arr, int sharkX, int sharkY, int sharkDir, int count) {
	fishMoving(arr, sharkX, sharkY);

	vector<pair<int, int>> nextVector;
	int nx = sharkX, ny = sharkY;
	while (!(nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)) {
		if (arr[nx][ny].first != -1) {
			nextVector.push_back({ nx,ny });
		}
		nx += dx[sharkDir];
		ny += dy[sharkDir];
	}

	if (nextVector.empty()) {
		ret = max(ret, count);
	}
	else {
		for (int i = 0; i < nextVector.size(); ++i) {
			int tmp = arr[nextVector[i].first][nextVector[i].second].first;
			arr[nextVector[i].first][nextVector[i].second].first = -1;
			search(arr, nextVector[i].first, nextVector[i].second, arr[nextVector[i].first][nextVector[i].second].second, count + tmp);
			arr[nextVector[i].first][nextVector[i].second].first = tmp;
		}
	}
}

void solve() {
	vector<vector<pair<int, int>>> arr(4, vector<pair<int, int>>(4));
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> arr[i][j].first >> arr[i][j].second;
			arr[i][j].second -= 1;
		}
	}

	int tmp = arr[0][0].first;
	arr[0][0].first = -1;
	search(arr, 0, 0, arr[0][0].second, tmp);
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}