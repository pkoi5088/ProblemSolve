#include <iostream>
#define endl '\n'
#define MAX 100

using namespace std;

/*
	https://www.acmicpc.net/problem/21278
*/

int N, M;
int graph[MAX][MAX];

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			graph[i][j] = -1;
		}
		graph[i][i] = 0;
	}
	
	while (M--) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}

	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (graph[i][k] == -1 || graph[k][j] == -1) continue;
				if (graph[i][j] == -1 || graph[i][k] + graph[k][j] < graph[i][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	int idx1=0, idx2=0, ret = 30000;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int tmp = 0;
			for (int k = 0; k < N; ++k) {
				tmp += 2 * min(graph[k][i], graph[k][j]);
			}
			if (tmp < ret) {
				idx1 = i, idx2 = j, ret = tmp;
			}
		}
	}
	cout << idx1 + 1 << ' ' << idx2 + 1 << ' ' << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}