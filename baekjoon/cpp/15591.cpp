#include <iostream>
#include <vector>
#include <queue>
#define MAX 5000
#define INF 1000000001
#define endl '\n'

using namespace std;

vector<pair<int, int>> graph[MAX];

int min(int a, int b) {
	return a < b ? a : b;
}

int query(int k, int v) {
	int cnt = 0;
	bool visit[MAX] = { false };
	queue<pair<int, int>> q;
	q.push({ v,INF });
	visit[v] = true;
	while (!q.empty()) {
		int now = q.front().first, usado = q.front().second;
		q.pop();
		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i].first, dist = graph[now][i].second, nextDist;
			if (visit[next]) continue;
			nextDist = min(dist, usado);
			q.push({ next,nextDist });
			visit[next] = true;
			if (nextDist >= k) cnt++;
		}
	}
	return cnt;
}

void solve() {
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N - 1; ++i) {
		int p, q, r;
		cin >> p >> q >> r;
		graph[p - 1].push_back({ q - 1,r });
		graph[q - 1].push_back({ p - 1,r });
	}

	while (Q--) {
		int k, v;
		cin >> k >> v;
		cout << query(k, v - 1) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
