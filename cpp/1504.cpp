#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 8000000
#define endl '\n'

using namespace std;

vector<pair<int, int>> graph[800];
int dist[800][2];

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

void solve() {
	int V, E, T1, T2;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back({ b - 1,c });
		graph[b - 1].push_back({ a - 1,c });
	}
	for (int i = 0; i < V; i++) {
		dist[i][0] = dist[i][1] = INF;
	}
	cin >> T1 >> T2;
	dist[T1 - 1][0] = dist[T2 - 1][1] = 0;

	//첫번째 다익스트라 T1->?
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ T1 - 1,0 });
	while (!pq.empty()) {
		int now = pq.top().first, cost = pq.top().second;
		pq.pop();
		if (dist[now][0] < cost)
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first, nextCost = graph[now][i].second;
			if (dist[next][0] > cost + nextCost) {
				pq.push({ next,cost + nextCost });
				dist[next][0] = cost + nextCost;
			}
		}
	}

	//두번째 다익스트라 T2->?
	pq.push({ T2 - 1,0 });
	while (!pq.empty()) {
		int now = pq.top().first, cost = pq.top().second;
		pq.pop();
		if (dist[now][1] < cost)
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first, nextCost = graph[now][i].second;
			if (dist[next][1] > cost + nextCost) {
				pq.push({ next,cost + nextCost });
				dist[next][1] = cost + nextCost;
			}
		}
	}
    
	int result = 2 * INF;
	result = min(dist[0][0] + dist[V - 1][1] + dist[T2-1][0], dist[V - 1][0] + dist[0][1] + dist[T2-1][0]);
	if (result >= INF)
		cout << -1;
	else
		cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
