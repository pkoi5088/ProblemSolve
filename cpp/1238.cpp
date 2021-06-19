#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 1000000
#define endl '\n'

using namespace std;

vector<pair<int, int>> graph[1000], reverseGraph[1000];
int dist[1000][2];
int N, M;

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

void solve() {
	int X;
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a - 1].push_back({ b - 1,c });
		reverseGraph[b - 1].push_back({ a - 1,c });
	}
	for (int i = 0; i < N; i++) {
		dist[i][0] = dist[i][1] = INF;
	}
	dist[X - 1][0] = dist[X - 1][1] = 0;

	//첫번째 다익스트라
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ X - 1,0 });
	while (!pq.empty()) {
		int now = pq.top().first, cost = pq.top().second;
		pq.pop();
		if (dist[now][0] < cost)
			continue;
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first, nextCost = graph[now][i].second;
			if (dist[next][0] > cost + nextCost) {
				pq.push({ next,cost + nextCost });
				dist[next][0] = cost + nextCost;
			}
		}
	}

	//두번째 다익스트라
	pq.push({ X - 1,0 });
	while (!pq.empty()) {
		int now = pq.top().first, cost = pq.top().second;
		pq.pop();
		if (dist[now][1] < cost)
			continue;
		for (int i = 0; i < reverseGraph[now].size(); i++) {
			int next = reverseGraph[now][i].first, nextCost = reverseGraph[now][i].second;
			if (dist[next][1] > cost + nextCost) {
				pq.push({ next,cost + nextCost });
				dist[next][1] = cost + nextCost;
			}
		}
	}

	int result = -1;
	for (int i = 0; i < N; i++) {
		if (i != X - 1) {
			result = max(dist[i][0] + dist[i][1], result);
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
