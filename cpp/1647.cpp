#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 100000
#define endl '\n'

using namespace std;

int parent[MAX];
int N, M;

struct Road {
	int a, b, c;
};

struct cmp {
	bool operator()(Road a, Road b) {
		return a.c > b.c;
	}
};

int Find(int a) {
	if (parent[a] == a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	parent[Find(a)] = parent[Find(b)];
}

void solve() {
	int tSum = 0, tMax = -1;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
	}
	priority_queue<Road, vector<Road>, cmp> pq;
	for (int i = 0; i < M; ++i) {
		Road x;
		int a, b, c;
		cin >> a >> b >> c;
		x.a = a - 1; x.b = b - 1; x.c = c;
		pq.push(x);
	}
	while (!pq.empty()) {
		int from = pq.top().a, to = pq.top().b, cost = pq.top().c;
		pq.pop();
		if (Find(from) != Find(to)) {
			Union(from, to);
			tSum += cost;
			tMax = max(tMax, cost);
		}
	}
	cout << tSum - tMax;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
