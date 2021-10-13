#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 1500
#define endl "\n"

using namespace std;

struct Node {
	int x, y, dist;
	Node(int ix, int iy, int id) :x(ix), y(iy), dist(id) {}
};

struct cmp {
	bool operator()(Node n1, Node n2) {
		return n1.dist > n2.dist;
	}
};

int depth[MAX][MAX], R, C;
int dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
string M[MAX];
pair<int, int> start;

void setdepth() {
	priority_queue<Node, vector<Node>, cmp> pq;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (M[i][j] == '.' || M[i][j] == 'L') {
				if (M[i][j] == 'L') start = { i,j };
				depth[i][j] = 0;
				pq.push(Node(i, j, 0));
			}
		}
	}

	while (!pq.empty()) {
		int x = pq.top().x, y = pq.top().y, dist = pq.top().dist;
		pq.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (depth[nx][ny] != -1) continue;
			depth[nx][ny] = dist + 1;
			pq.push(Node(nx, ny, dist + 1));
		}
	}
}

int getRet() {
	int ret = -1;
	priority_queue<Node, vector<Node>, cmp> pq;
	M[start.first][start.second] = '.';
	pq.push(Node(start.first, start.second, 0));
	depth[start.first][start.second] = -1;
	while (!pq.empty()) {
		int x = pq.top().x, y = pq.top().y, dist = pq.top().dist;
		pq.pop();
		if (M[x][y] == 'L') return ret;
		ret = max(ret, dist);

		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (depth[nx][ny] == -1) continue;
			pq.push(Node(nx, ny, depth[nx][ny]));
			depth[nx][ny] = -1;
		}
	}
}

void solve() {
	memset(depth, -1, sizeof(depth));
	cin >> R >> C;
	for (int i = 0; i < R; ++i)
		cin >> M[i];
	setdepth();
	cout << getRet();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}