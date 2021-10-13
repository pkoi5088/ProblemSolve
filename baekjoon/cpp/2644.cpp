#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<vector<int>> graph;
vector<bool> visit;

int solve() {
	int N, start, end, M;
	cin >> N;
	graph.resize(N);
	visit.resize(N, false);
	cin >> start >> end >> M;
	start -= 1; end -= 1;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}

	queue<pair<int, int>> q;
	q.push({ start,0 });
	visit[start] = true;
	while (!q.empty()) {
		int now = q.front().first, dist = q.front().second;
		q.pop();
		if (now == end)
			return dist;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (visit[next] == false) {
				visit[next] = true;
				q.push({ next,dist + 1 });
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}
