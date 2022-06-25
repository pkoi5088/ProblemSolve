#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/13023
*/

vector<vector<int>> graph;
vector<int> visit;
int ret = 0;

void dfs(int idx,int depth) {
	if (depth >= 4) {
		ret = 1;
	}
	else {
		for (int i = 0; i < graph[idx].size(); ++i) {
			int next = graph[idx][i];
			if (visit[next] == 0) {
				visit[next] = 1;
				dfs(next, depth + 1);
				visit[next] = 0;
			}
		}
	}
}

void solve() {
	int N, M;
	cin >> N >> M;
	graph.resize(N);
	visit.resize(N, 0);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 0; i < N; ++i) {
		visit[i] = 1;
		dfs(i, 0);
		visit[i] = 0;
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}