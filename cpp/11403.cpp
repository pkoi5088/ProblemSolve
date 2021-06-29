#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph, result;
int N;

void bfs(int start) {
	vector<int> visit;
	visit.resize(N, 0);
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < N; i++) {
			if (graph[now][i] == 1 && visit[i] == 0) {
				visit[i] = 1;
				result[start][i] = 1;
				q.push(i);
			}
		}
	}
}

void solve() {
	cin >> N;
	graph.resize(N);
	result.resize(N);
	for (int i = 0; i < N; i++) {
		graph[i].resize(N);
		result[i].resize(N, 0);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		bfs(i);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}