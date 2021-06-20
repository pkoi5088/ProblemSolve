#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Node {
public:
	int x, y, dist, state;
	Node(int ix, int iy, int id, int is) :x(ix), y(iy), dist(id), state(is) {};
};

int graph[1000][1000] = { 0, };
bool visit[1000][1000][2] = { false, };
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 }; //좌 우 상 하
int N, M;

int bfs() {
	queue<Node> q;
	q.push(Node(0, 0, 1, 0));
	visit[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dist = q.front().dist, state = q.front().state;
		q.pop();
		if (x == N - 1 && y == M - 1)
			return dist;
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (graph[nx][ny] == 0 && visit[nx][ny][state] == false) {
					visit[nx][ny][state] = true;
					q.push(Node(nx, ny, dist + 1, state));
				}
				if (state == 0 && graph[nx][ny] == 1 && visit[nx][ny][1] == false) {
					visit[nx][ny][1] = true;
					q.push(Node(nx, ny, dist + 1, 1));
				}
			}
		}
	}
	return -1;
}

int solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			graph[i][j] = s[j] - '0';
		}
	}

	return bfs();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve() << '\n';
	return 0;
}