#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/11725
*/

vector<vector<int>> graph;
vector<int> parent;
int N;

void solve() {
	queue<int> q;
	cin >> N;
	graph.resize(N);
	parent.resize(N, -1);
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}

	q.push(0);
	parent[0] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (parent[next] == -1) {
				parent[next] = now;
				q.push(next);
			}
		}
	}

	for (int i = 1; i < N; i++) {
		cout << parent[i] + 1 << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
