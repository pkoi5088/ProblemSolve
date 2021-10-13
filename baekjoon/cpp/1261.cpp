#include <iostream>
#include <queue>
#include <cstring>
#define MAX 100
#define endl '\n'

using namespace std;

struct Node {
	int x, y, dist;
	Node(int ix, int iy, int id) {
		x = ix, y = iy, dist = id;
	}
};

struct cmp {
	bool operator()(Node n1, Node n2) {
		return n1.dist > n2.dist;
	}
};

int map[MAX][MAX], visit[MAX][MAX];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void solve() {
	int N, M;
	cin >> M >> N;
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j) {
			map[i][j] = s[j] - '0';
		}
	}

	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push(Node(0, 0, 0));
	visit[0][0] = 0;
	while (!pq.empty()) {
		int x = pq.top().x, y = pq.top().y, dist = pq.top().dist;
		pq.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny] != -1) continue;
			pq.push(Node(nx, ny, dist + map[nx][ny]));
			visit[nx][ny] = dist + map[nx][ny];
		}
	}
	cout << visit[N - 1][M - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
