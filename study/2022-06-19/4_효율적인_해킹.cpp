#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    https://www.acmicpc.net/problem/1325
*/

int N, M;
vector<vector<int>> graph;
vector<bool> check;
int cnt = 0;

void init() {
	check.clear();
	check.resize(N);
	cnt = 0;
}

void dfs(int idx) {
	cnt += 1;
	check[idx] = true;
	for (int i = 0; i < graph[idx].size(); ++i) {
		int next = graph[idx][i];
		if (check[next] == false) {
			dfs(next);
		}
	}
}

void solve() {
	cin >> N >> M;
	graph.resize(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		graph[b - 1].push_back(a - 1);
	}

	int retCount = 0;
	vector<int> ret;
	for (int i = 0; i < N; ++i) {
		init();
		dfs(i);

		if (retCount < cnt) {
			retCount = cnt;
			ret.clear();
			ret.push_back(i);
		}
		else if (retCount == cnt) {
			ret.push_back(i);
		}
	}

	sort(ret.begin(), ret.end());
	for (int i : ret) {
		cout << i + 1 << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
