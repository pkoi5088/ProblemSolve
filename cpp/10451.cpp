#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void dfs(int n, vector<int>& graph, vector<bool>& visit) {
	if (visit[graph[n] - 1] == false) {
		visit[graph[n] - 1] = true;
		dfs(graph[n] - 1, graph, visit);
	}
}

void solve() {
	vector<int> graph;
	vector<bool> visit;
	int N, result = 0;
	cin >> N;
	graph.resize(N);
	visit.resize(N, false);
	for (int i = 0; i < N; ++i) {
		cin >> graph[i];
	}

	for (int i = 0; i < N; ++i) {
		if (visit[i] == false) {
			visit[i] = true;
			result += 1;
			dfs(i, graph, visit);
		}
	}
	cout << result << endl;
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
