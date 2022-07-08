#include <iostream>
#include <string>
#include <queue>
#define endl '\n'
#define MAX 300

using namespace std;

/*
	https://www.acmicpc.net/problem/4179
*/

pair<int, int> jihoon;
int R, C;
vector<string> arr;
vector<vector<int>> deadline;
vector<vector<bool>> visit;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void solve() {
	queue<pair<int, int>> q;
	cin >> R >> C;
	arr.resize(R);
	deadline.resize(R);
	visit.resize(R);
	for (int i = 0; i < R; ++i) {
		deadline[i].resize(C, -1);
		visit[i].resize(C, false);
		cin >> arr[i];
		for (int j = 0; j < C; ++j) {
			if (arr[i][j] == 'J') {
				jihoon = { i,j };
			}
			else if (arr[i][j] == 'F') {
				q.push({ i,j });
				deadline[i][j] = 0;
			}
		}
	}
	//불 번지는 시간, x초 미만이면 안전하다.
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (arr[nx][ny] == '#' || deadline[nx][ny] != -1) continue;
			q.push({ nx,ny });
			deadline[nx][ny] = deadline[x][y] + 1;
		}
	}

	//이동시간 구하기
	queue<pair<pair<int, int>, int>> q2;
	q2.push({ jihoon,0 });
	visit[jihoon.first][jihoon.second] = true;
	while (!q2.empty()) {
		int x = q2.front().first.first, y = q2.front().first.second, time = q2.front().second;
		q2.pop();

		if (x == 0 || x == R - 1 || y == 0 || y == C - 1) {
			cout << time + 1;
			return;
		}

		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (arr[nx][ny] == '#' || visit[nx][ny] || (time + 1 >= deadline[nx][ny] && deadline[nx][ny] != -1)) continue;
			q2.push({ { nx,ny },time + 1 });
			visit[nx][ny] = true;
		}
	}
	cout << "IMPOSSIBLE";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}