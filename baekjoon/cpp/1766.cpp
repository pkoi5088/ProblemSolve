#include <iostream>
#include <queue>
#include <vector>
#define MAX 32000
#define endl '\n'

using namespace std;

vector<int> graph[MAX];
int indegree[MAX] = { 0 };

void solve() {
	int N, M;
	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		indegree[b - 1]++;
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; ++i) {
		if (indegree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int x = pq.top();
		pq.pop();
		for (int i = 0; i < graph[x].size(); ++i) {
			if (--indegree[graph[x][i]] == 0)
				pq.push(graph[x][i]);
		}
		cout << x + 1 << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
