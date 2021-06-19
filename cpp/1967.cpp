#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visit;
int farVertex, farDist;

void reset() {
	for (int i = 0; i < visit.size(); i++) {
		visit[i] = false;
	}
	farDist = -1;
}

void getFar(int start) {
	queue<pair<int, int>> q;
	q.push({ start,0 });
	visit[start] = true;
	while (!q.empty()) {
		int now = q.front().first, dist = q.front().second;
		q.pop();
		if (dist > farDist) {
			farVertex = now;
			farDist = dist;
		}
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first, cost = graph[now][i].second;
			if (visit[next] == false) {
				q.push({ next,dist + cost });
				visit[next] = true;
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;
	graph.resize(n);
	visit.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back({ b - 1,c });
		graph[b - 1].push_back({ a - 1,c });
	}

	int start;
	reset();
	getFar(0);
	start = farVertex;
	reset();
	getFar(start);
	cout << farDist;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
