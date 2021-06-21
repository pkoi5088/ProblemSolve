#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> graph;
vector<int> visit;
int V, E;

void solve() {
	cin >> V >> E;
	graph.clear();
	visit.clear();
	graph.resize(V);
	visit.resize(V, -1);
	for (int i = 0; i < E; i++) {
		int x, y;
		cin >> x >> y;
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}

	for (int i = 0; i < V; i++) {
		if (visit[i] != -1)
			continue;
		queue<pair<int, int>> q;
		q.push({ i,1 });
		visit[i] = 1;
		while (!q.empty()) {
			int now = q.front().first, num = q.front().second;
			q.pop();
			for (int l = 0; l < graph[now].size(); l++) {
				int next = graph[now][l];
				if (visit[next] == num) {
					cout << "NO\n";
					return;
				}
				else if (visit[next] == -1) {
					q.push({ next,!num });
					visit[next] = !num;
				}
			}
		}
	}
	cout << "YES\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int K;
	cin >> K;
	while (K--)
		solve();
	return 0;
}
