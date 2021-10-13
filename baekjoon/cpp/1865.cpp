#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 2100000000
#define endl '\n'

using namespace std;

void solve() {
	vector<vector<pair<int, int>>> graph;
	vector<int> dist;
	int N, M, W;
	cin >> N >> M >> W;
	graph.resize(N);
	dist.resize(N, INF);
	for (int i = 0; i < M; i++) {
		int S, E, T;
		cin >> S >> E >> T;
		graph[S - 1].push_back({ E - 1,T });
		graph[E - 1].push_back({ S - 1,T });
	}
	for (int i = 0; i < W; i++) {
		int S, E, T;
		cin >> S >> E >> T;
		graph[S - 1].push_back({ E - 1,-1 * T });
	}

	dist[0] = 0;
	bool updated = false;
	for (int r = 0; r < N; r++) {
		updated = false;
		for (int now = 0; now < N; now++) {
			for (int i = 0; i < graph[now].size(); i++) {
				int next = graph[now][i].first, cost = graph[now][i].second;
				if (dist[next] > dist[now] + cost) {
					dist[next] = dist[now] + cost;
					updated = true;
				}
			}
		}
		if (!updated) break;
	}
	if (updated) {
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
