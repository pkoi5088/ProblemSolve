#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 10001
#define endl '\n'

using namespace std;

int cost[MAX] = { 0 }, parent[MAX];
int N, M, k;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	parent[Find(x)] = parent[Find(y)];
}

void solve() {
	int sum = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	cin >> N >> M >> k;
	for (int i = 1; i < N + 1; ++i) {
		cin >> cost[i];
		pq.push({ cost[i],i });
	}
	for (int i = 0; i < N + 1; ++i) {
		parent[i] = i;
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}

	while (!pq.empty()) {
		int now = pq.top().second, nowCost = pq.top().first;
		pq.pop();
		if (Find(0) == Find(now)) continue;
		if (k < sum + nowCost) {
			cout << "Oh no";
			return;
		}
		else {
			Union(now, 0);
			sum += nowCost;
		}
	}
	cout << sum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
