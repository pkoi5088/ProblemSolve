#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 20000
#define endl '\n'

using namespace std;

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

void solve() {
	vector<pair<int, int>> graph[MAX];
	int V, E, K, dist[MAX];
	cin >> V >> E >> K;
	memset(dist, -1, sizeof(dist));
	while (E--) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u - 1].push_back({ v - 1,w });
	}

	dist[K - 1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ K - 1,0 });
	while (!pq.empty()) {
		int now = pq.top().first, length = pq.top().second;
		pq.pop();
		if (dist[now] != -1 && dist[now] < length) continue;
		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i].first, weight = graph[now][i].second;
			if (dist[next] == -1 || length + weight < dist[next]) {
				pq.push({ next,length + weight });
				dist[next] = length + weight;
			}
		}
	}

	for (int i = 0; i < V; ++i) {
		if (dist[i] == -1) cout << "INF" << endl;
		else cout << dist[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
