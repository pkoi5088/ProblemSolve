#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 1000
#define endl '\n'

using namespace std;

class node {
public:
	int now, cost;
	node(int in, int ic) :now(in), cost(ic) {};
};

struct cmp {
	bool operator()(node n1, node n2) {
		return n1.cost > n2.cost;
	}
};

vector<pair<int, int>> graph[MAX];

void solve() {
	priority_queue<node, vector<node>, cmp> pq;
	int N, M, dist[MAX], start, end;
	cin >> N >> M;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < M; ++i) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from - 1].push_back({ to - 1,cost });
	}
	cin >> start >> end;
	start -= 1, end -= 1;

	pq.push(node(start, 0));
	dist[start] = 0;
	while (!pq.empty()) {
		int now = pq.top().now, cost = pq.top().cost;
		pq.pop();
		if (dist[now] != -1 && dist[now] < cost) continue;
		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i].first, nextCost = cost + graph[now][i].second;
			if (dist[next] == -1 || dist[next] > nextCost) {
				pq.push(node(next, nextCost));
				dist[next] = nextCost;
			}
		}
	}
	cout << dist[end];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
