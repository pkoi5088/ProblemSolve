#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 300
#define INF 1000001

using namespace std;

/*
	https://www.acmicpc.net/problem/23286
*/

int N, M, T;
int graph[MAX][MAX];

void solve() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < M; ++i) {
		int s, e, c;
		cin >> s >> e >> c;
		graph[s - 1][e - 1] = c;
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (graph[i][k] == INF || graph[k][j] == INF) continue;
				int value = max(graph[i][k], graph[k][j]);
				graph[i][j] = min(graph[i][j], value);
			}
		}
	}

	while (T--) {
		int s, e;
		cin >> s >> e;
		if (graph[s - 1][e - 1] == INF) cout << -1 << endl;
		else cout << graph[s - 1][e - 1] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}