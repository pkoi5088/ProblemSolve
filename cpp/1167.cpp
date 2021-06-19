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

vector<vector<pair<int, int>>> tree;
vector<int> dist;
int V;

void far(int n) {
	for (int i = 0; i < tree[n].size(); i++) {
		int next = tree[n][i].first, nextDist = dist[n] + tree[n][i].second;
		if (dist[next] == -1) {
			dist[next] = nextDist;
			far(next);
		}
	}
}

void solve() {
	cin >> V;
	tree.resize(V);
	dist.resize(V, -1);
	for (int i = 0; i < V; i++) {
		int x;
		cin >> x;
		while (true) {
			int a, b;
			cin >> a;
			if (a == -1)
				break;
			cin >> b;
			tree[x - 1].push_back({ a - 1,b });
		}
	}

	int start, result = -1;
	dist[0] = 0;
	far(0);
	for (int i = 0; i < V; i++) {
		if (dist[i] > result) {
			start = i;
			result = dist[i];
		}
		dist[i] = -1;
	}

	dist[start] = 0;
	far(start);
	result = -1;
	for (int i = 0; i < V; i++) {
		if (dist[i] > result) {
			result = dist[i];
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
