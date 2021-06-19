#include <iostream>
#include <queue>

using namespace std;

int solve() {
	vector<int> time, dist, indegree;
	vector<vector<int>> graph;
	int N, K, G;
	cin >> N >> K;
	time.resize(N);
	graph.resize(N);
	indegree.resize(N, 0);
	dist.resize(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> time[i];
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		graph[x - 1].push_back(y - 1);
		indegree[y - 1]++;
	}
	cin >> G;
	G -= 1;

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
		if (now == G)
			return dist[G];
		
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			indegree[next] -= 1;
			if (indegree[next] == 0) {
				q.push(next);
			}
			if (dist[next] < dist[now] + time[next]) {
				dist[next] = dist[now] + time[next];
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		cout << solve() << endl;
	}
	return 0;
}