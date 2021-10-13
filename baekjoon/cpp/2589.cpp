#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define MAX 50
#define endl '\n'

using namespace std;

string map[MAX];
int N, M;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

int getFarLoc(int x, int y) {
	int visit[MAX][MAX] = { 0, };
	int dist = 0;
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0,{x,y} });
	visit[x][y] = 1;
	while (!q.empty()) {
		int nowDist = q.front().first, nowX = q.front().second.first, nowY = q.front().second.second;
		q.pop();
		if (dist < nowDist) {
			dist = nowDist;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = nowX + dx[i], ny = nowY + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (map[nx][ny] == 'W' || visit[nx][ny] == 1) continue;
			q.push({ nowDist + 1,{nx,ny} });
			visit[nx][ny] = 1;
		}
	}
	return dist;
}

void solve() {
	int ret = -1;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> map[i];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 'L') {
				int dist = getFarLoc(i, j);
				if (ret < dist) ret = dist;
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
