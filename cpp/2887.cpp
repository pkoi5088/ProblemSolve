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

struct Planet {
	int index, x, y, z;
};

struct Node {
	int from, to;
	long long dist;
};

struct cmp {
	bool operator()(Node a, Node b) {
		return a.dist > b.dist;
	}
};

vector<Planet> v;
int parent[MAX];
int N;

bool cmpX(Planet a, Planet b) {
	return a.x < b.x;
}

bool cmpY(Planet a, Planet b) {
	return a.y < b.y;
}

bool cmpZ(Planet a, Planet b) {
	return a.z < b.z;
}

int Find(int x) {
	if (parent[x] == x) return parent[x];
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	parent[Find(x)] = parent[Find(y)];
}

void solve() {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
		v[i].index = i;
		cin >> v[i].x >> v[i].y >> v[i].z;
	}

	priority_queue<Node, vector<Node>, cmp> pq;
	Node tmp;
	sort(v.begin(), v.end(), cmpX);
	for (int i = 0; i < N - 1; ++i) {
		tmp.from = v[i].index;
		tmp.to = v[i + 1].index;
		tmp.dist = abs(v[i].x - v[i + 1].x);
		pq.push(tmp);
	}
	sort(v.begin(), v.end(), cmpY);
	for (int i = 0; i < N - 1; ++i) {
		tmp.from = v[i].index;
		tmp.to = v[i + 1].index;
		tmp.dist = abs(v[i].y - v[i + 1].y);
		pq.push(tmp);
	}
	sort(v.begin(), v.end(), cmpZ);
	for (int i = 0; i < N - 1; ++i) {
		tmp.from = v[i].index;
		tmp.to = v[i + 1].index;
		tmp.dist = abs(v[i].z - v[i + 1].z);
		pq.push(tmp);
	}

	long long result = 0;
	while (!pq.empty()) {
		int a = pq.top().from, b = pq.top().to;
		long long cost = pq.top().dist;
		pq.pop();
		if (Find(a) != Find(b)) {
			Union(a, b);
			result += cost;
		}
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
