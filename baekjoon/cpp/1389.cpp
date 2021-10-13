#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

int dist[100][100] = { 0 };
int N, M;

void solve() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		dist[x - 1][y - 1] = 1;
		dist[y - 1][x - 1] = 1;
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (dist[i][k] && dist[k][j]) {
					if (dist[i][j] == 0)
						dist[i][j] = dist[i][k] + dist[k][j];
					else
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	int result = 0, resultDist = 0;
	for (int i = 0; i < N; i++) {
		resultDist += dist[0][i];
	}

	for (int i = 1; i < N; i++) {
		int t = 0;
		for (int j = 0; j < N; j++) {
			t += dist[i][j];
		}
		if (t < resultDist) {
			resultDist = t;
			result = i;
		}
	}
	cout << result + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
