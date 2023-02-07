#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 300
#define INF 1000001

using namespace std;

/*
	https://www.acmicpc.net/problem/23286
*/

int N, M, T;
int graph[MAX][MAX];

class Node {
public:
	int n, height;
	Node(int in, int ih) {
		n = in, height = ih;
	}
};

struct cmp {
	bool operator()(Node n1, Node n2) {
		return n1.height > n2.height;
	}
};

int getMinHight(int start, int end) {
	int hurdle[MAX];
	for (int i = 0; i < N; ++i) {
		hurdle[i] = INF;
	}

	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push(Node(start, 0));
	hurdle[start] = 0;
	while (!pq.empty()) {
		int now = pq.top().n, height = pq.top().height;
		pq.pop();
		if (hurdle[now] < height) continue;

		for (int next = 0; next < N; ++next) {
			if (graph[now][next] == -1) continue;
			if (max(height, graph[now][next]) < hurdle[next]) {
				pq.push(Node(next, max(height, graph[now][next])));
				hurdle[next] = max(height, graph[now][next]);
			}
		}
	}
	if (hurdle[end] == INF) return - 1;
	return hurdle[end];
}

void solve() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			graph[i][j] = -1;
		}
	}
	for (int i = 0; i < M; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		graph[s - 1][e - 1] = c;
	}

	for (int i = 0; i < T; ++i) {
		int s, e;
		cin >> s >> e;
		cout << getMinHight(s - 1, e - 1) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}