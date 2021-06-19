#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define INF -1000001

using namespace std;

class Node {
public:
	int from, to, weight;
	Node(int a, int b, int c) :from(a), to(b), weight(c) {};
};

struct cmp {
	bool operator()(Node n1, Node n2) {
		return n1.weight > n2.weight;
	}
};

vector<int> parent;
priority_queue<Node, vector<Node>, cmp> pq;

int Find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	parent[Find(y)] = Find(x);
}

int solve() {
	int V, E, result = 0;
	cin >> V >> E;
	parent.resize(V);
	for (int i = 0; i < V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		pq.push(Node(A - 1, B - 1, C));
	}

	while (!pq.empty()) {
		int from = pq.top().from, to = pq.top().to, weiht = pq.top().weight;
		pq.pop();
		//사이클 생성경우
		if (Find(from) == Find(to))
			continue;
		result += weiht;
		Union(from, to);
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}
