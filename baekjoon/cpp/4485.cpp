#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 125
#define INF 125*125*10

using namespace std;

/*
	https://www.acmicpc.net/problem/4485
*/

struct Node {
	int x, y, cost;
	Node(int _x, int _y, int _cost) {
		x = _x;
		y = _y;
		cost = _cost;
	}
};

struct cmp {
	bool operator()(Node n1, Node n2) {
		return n1.cost > n2.cost;
	}
};

int N, cnt = 1;
int arr[MAX][MAX], cache[MAX][MAX];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void init() {
	cin >> N;
	if (N == 0) return;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
			cache[i][j] = INF;
		}
	}
}

int dijkstra() {
	int ret = INF;
	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push(Node(0, 0, arr[0][0]));
	cache[0][0] = arr[0][0];
	while (!pq.empty()) {
		int x = pq.top().x, y = pq.top().y, cost = pq.top().cost;
		pq.pop();

		if (cost > cache[x][y]) continue;
		if (x == N - 1 && y == N - 1) return cost;

		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (cost + arr[nx][ny] < cache[nx][ny]) {
				pq.push(Node(nx, ny, cost + arr[nx][ny]));
				cache[nx][ny] = cost + arr[nx][ny];
			}
		}
	}
}

void solve() {
	while (true) {
		init();
		if (N == 0) return;
		cout << "Problem " << cnt << ": " << dijkstra() << endl;
        cnt++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}