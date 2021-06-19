#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> indegree, time, dist;
vector<vector<int>> graph;

void solve() {
	int N;
	cin >> N;
	indegree.resize(N, 0);
	time.resize(N);
	graph.resize(N);
	dist.resize(N, -1);
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		time[i] = x;
		cin >> x;
		while (x != -1) {
			indegree[i] += 1;
			graph[x - 1].push_back(i);
			cin >> x;
		}
	}
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			dist[i] = time[i];
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			dist[next] = max(dist[next], dist[now] + time[next]);
			indegree[next] -= 1;
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << dist[i] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}