#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 100000000
#define endl '\n'

using namespace std;

struct Node {
	int dist;
	vector<int> route;
};

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

void solve() {
	int n, m, start, end;
	vector<vector<pair<int,int>>> graph;
	vector<Node> result;
	cin >> n >> m;
	graph.resize(n);
	result.resize(n);
	for (int i = 0; i < n; ++i)
		result[i].dist = INF;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back({ b - 1,c });
	}
	cin >> start >> end;

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ start - 1,0 });
	result[start - 1].dist = 0;
	result[start - 1].route.push_back(start - 1);
	while (!pq.empty()) {
		int now = pq.top().first, d = pq.top().second;
		pq.pop();
		for (int i = 0; i < graph[now].size(); ++i) {
			int next = graph[now][i].first, cost = graph[now][i].second;
			if (result[next].dist > d + cost) {
				pq.push({ next,d + cost });
				result[next].dist = d + cost;
				result[next].route = result[now].route;
				result[next].route.push_back(next);
			}
		}
	}

	cout << result[end - 1].dist << endl;
	cout << result[end - 1].route.size() << endl;
	for (int i = 0; i < result[end - 1].route.size(); ++i) {
		cout << result[end - 1].route[i] + 1 << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
