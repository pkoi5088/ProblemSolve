#include <iostream>
#include <vector>
#include <queue>
#define MAX 2000
#define endl '\n'

using namespace std;

struct node {
	int a, b, dist;
};

struct cmp {
	bool operator()(node n1, node n2) {
		return n1.dist > n2.dist;
	}
};

int parent[MAX];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	parent[Find(x)] = parent[Find(y)];
}

void solve() {
	vector<pair<int, int>> vertex;
	int N, C, cost = 0;
	cin >> N >> C;
	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		vertex.push_back({ x,y });
	}

	for (int i = 0; i < N; ++i) parent[i] = i;
	priority_queue<node, vector<node>, cmp> pq;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			node tmp;
			tmp.a = i;
			tmp.b = j;
			tmp.dist = (vertex[i].first - vertex[j].first) * (vertex[i].first - vertex[j].first) + (vertex[i].second - vertex[j].second) * (vertex[i].second - vertex[j].second);
			if (tmp.dist>= C)
				pq.push(tmp);
		}
	}

	while (!pq.empty()) {
		int a = pq.top().a, b = pq.top().b, dist = pq.top().dist;
		pq.pop();
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		cost += dist;
	}

	for (int i = 1; i < N; ++i) {
		if (Find(0) != Find(i)) {
			cout << -1;
			return;
		}
	}
	cout << cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
