#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	int n;
	vector<vector<bool>> graph;
	vector<bool> visit;
	vector<pair<int, int>> loc;
	queue<int> q;
	cin >> n;
	n += 2;
	graph.resize(n);
	visit.resize(n, false);
	loc.resize(n);
	for (int i = 0; i < n; i++) {
		graph[i].resize(n, false);
	}
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		loc[i].first = x; loc[i].second = y;
		for (int j = 0; j < i; j++) {
			if (abs(x - loc[j].first) + abs(y - loc[j].second) <= 1000) {
				graph[i][j] = graph[j][i] = true;
			}
		}
	}

	q.push({ 0 });
	visit[0] = true;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == n - 1) {
			cout << "happy" << endl;
			return;
		}

		for (int next = 0; next < n; next++) {
			if (now == next)
				continue;
			if (graph[now][next] && visit[next] == false) {
				q.push(next);
				visit[next] = true;
			}
		}
	}
	cout << "sad" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
