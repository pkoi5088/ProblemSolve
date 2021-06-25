#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Point {
public:
	int x, y, dist;

	Point(int ix, int iy, int id) :x(ix), y(iy), dist(id) {};

	bool operator==(Point p2) {
		return x == p2.x && y == p2.y;
	}
};

vector<string> graph;
int water[50][50] = { 0 };
bool visit[50][50] = { false };
int R, C, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void solve() {
	queue<Point> q;
	cin >> R >> C;
	graph.resize(R);
	for (int i = 0; i < R; i++) {
		cin >> graph[i];
		for (int j = 0; j < C; j++) {
			if (graph[i][j] == '*') {
				q.push(Point(i, j, 0));
				visit[i][j] = true;
			}
			water[i][j] = 200;
		}
	}

	//물 영역 표시
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dist = q.front().dist;
		q.pop();
		for (int l = 0; l < 4; l++) {
			int nx = x + dx[l], ny = y + dy[l];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (visit[nx][ny] == false && graph[nx][ny] == '.') {
					q.push(Point(nx, ny, dist + 1));
					visit[nx][ny] = true;
					water[nx][ny] = dist + 1;
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j] == 'S') {
				q.push(Point(i, j, 0));
				visit[i][j] = true;
			}
			else {
				visit[i][j] = false;
			}
		}
	}

	//실제 이동
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dist = q.front().dist;
		q.pop();
		for (int l = 0; l < 4; l++) {
			int nx = x + dx[l], ny = y + dy[l];
			if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (graph[nx][ny] == 'D') {
					cout << dist + 1;
					return;
				}
				else if (visit[nx][ny] == false && graph[nx][ny] == '.' && dist + 1 < water[nx][ny]) {
					q.push(Point(nx, ny, dist + 1));
					visit[nx][ny] = true;
				}
			}
		}
	}
	cout << "KAKTUS";
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
