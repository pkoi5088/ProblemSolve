#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#define MAX 100
#define endl '\n'

using namespace std;

struct Node {
	int from, to;
	double dist;
};

struct cmp {
	bool operator()(Node a, Node b) {
		return a.dist > b.dist;
	}
};

pair<double, double> star[MAX];
int parent[MAX];
int N;

int Find(int x) {
	if (parent[x] == x) return parent[x];
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	parent[Find(x)] = parent[Find(y)];
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> star[i].first >> star[i].second;
		parent[i] = i;
	}

	priority_queue<Node, vector<Node>, cmp> pq;
	Node tmp;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			tmp.from = j;
			tmp.to = i;
			double a = abs(star[i].first - star[j].first), b = abs(star[i].second - star[j].second);
			tmp.dist = a * a + b * b;
			pq.push(tmp);
		}
	}

	double result = 0.0;
	while (!pq.empty()) {
		int a = pq.top().from, b = pq.top().to;
		double cost = pq.top().dist;
		pq.pop();
		if (Find(a) != Find(b)) {
			result += sqrt(cost);
			Union(a, b);
		}
	}
	printf("%.2lf", result);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
