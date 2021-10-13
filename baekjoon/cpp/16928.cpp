#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#define MAX 101
#define endl '\n'

using namespace std;

int graph[MAX] = { 0 };
int dist[MAX];

void solve() {
	memset(dist, -1, sizeof(dist));
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N + M; ++i) {
		int u, v;
		cin >> u >> v;
		graph[u] = v;
	}

	queue<int> q;
	q.push(1);
	dist[1] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= 6; ++i) {
			int next = now + i;
			if (next <= 100) {
				if (graph[next] != 0)
					next = graph[next];
				if (dist[next] == -1) {
					dist[next] = dist[now] + 1;
					q.push(next);
				}
			}
		}
	}
	cout << dist[100];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
