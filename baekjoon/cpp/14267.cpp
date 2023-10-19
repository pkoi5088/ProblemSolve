#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

int N, M;
vector<int> degree;
vector<vector<int>> child;

void solve() {
	cin >> N >> M;
	child.resize(N);
	degree.resize(N, 0);
	for (int i = 0; i < N; ++i) {
		int t;
		cin >> t;
		if (t == -1) continue;
		child[t - 1].push_back(i);
	}

	while (M--) {
		int a, b;
		cin >> a >> b;
		degree[a - 1] += b;
	}

	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int c : child[now]) {
			degree[c] += degree[now];
			q.push(c);
		}
	}

	for (int c : degree) {
		cout << c << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}