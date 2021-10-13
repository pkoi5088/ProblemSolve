#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 1500
#define endl '\n'

using namespace std;

void solve() {
	vector<vector<int>> graph;
	vector<int> item;
	int n, m, r, result = -1;
	cin >> n >> m >> r;
	graph.resize(n);
	item.resize(n);
	for (int i = 0; i < n; ++i) {
		graph[i].resize(n, INF);
		cin >> item[i];
		graph[i][i] = 0;
	}
	for (int i = 0; i < r; ++i) {
		int a, b, l;
		cin >> a >> b >> l;
		graph[a - 1][b - 1] = l;
		graph[b - 1][a - 1] = l;
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
		int tmp = 0;
		for (int j = 0; j < n; ++j) {
			if (graph[i][j] <= m) {
				tmp += item[j];
			}
		}
		result = max(result, tmp);
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
