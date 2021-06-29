#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 10000000
#define endl '\n'

using namespace std;

void solve() {
	vector<vector<int>> graph;
	int n, m;
	cin >> n >> m;
	graph.resize(n);
	for (int i = 0; i < n; ++i)
		graph[i].resize(n, INF);
	for (int i = 0; i < n; ++i)
		graph[i][i] = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (graph[a - 1][b - 1] > c)
			graph[a - 1][b - 1] = c;
	}

	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << (graph[i][j] == INF ? 0 : graph[i][j]) << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
