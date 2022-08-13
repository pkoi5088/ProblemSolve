#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/17144
*/

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void solve() {
	vector<vector<int>> graph, addGraph;
	int R, C, T, cleanerX, cleanerY, ret = 0;
	cin >> R >> C >> T;
	graph.resize(R);
	addGraph.resize(R);
	for (int i = 0; i < R; ++i) {
		graph[i].resize(C);
		addGraph[i].resize(C, 0);
	}
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> graph[i][j];
			if (graph[i][j] == -1) {
				cleanerX = i;
				cleanerY = j;
			}
		}
	}

	while (T--) {
		queue<pair<int, int>> q;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (graph[i][j] > 0) {
					int plus = graph[i][j] / 5;
					for (int k = 0; k < 4; ++k) {
						int nx = i + dx[k], ny = j + dy[k];
						if (nx >= 0 && nx < R && ny >= 0 && ny < C && graph[nx][ny] != -1) {
							addGraph[nx][ny] += plus;
							graph[i][j] -= plus;
						}
					}
				}
			}
		}

		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				graph[i][j] += addGraph[i][j];
				addGraph[i][j] = 0;
			}
		}

		//아래부분
		for (int i = cleanerY; i >= 1; --i) {
			graph[cleanerX][i] = graph[cleanerX][i - 1];
		}
		for (int i = cleanerX; i < R - 1; ++i) {
			graph[i][0] = graph[i + 1][0];
		}
		for (int i = 0; i < C - 1; ++i) {
			graph[R - 1][i] = graph[R - 1][i + 1];
		}
		graph[cleanerX - 1][cleanerY] = graph[cleanerX][cleanerY] = 0;
		for (int i = R - 1; i > cleanerX; --i) {
			graph[i][C - 1] = graph[i - 1][C - 1];
		}
		for (int i = C - 1; i > cleanerY; --i) {
			graph[cleanerX][i] = graph[cleanerX][i - 1];
		}

		//윗부분
		for (int i = cleanerY; i >= 1; --i) {
			graph[cleanerX - 1][i] = graph[cleanerX - 1][i - 1];
		}
		for (int i = cleanerX - 1; i >= 1; --i) {
			graph[i][0] = graph[i - 1][0];
		}
		for (int i = 0; i < C - 1; ++i) {
			graph[0][i] = graph[0][i + 1];
		}
		graph[cleanerX - 1][cleanerY] = graph[cleanerX][cleanerY] = 0;
		for (int i = 0; i < cleanerX - 1; ++i) {
			graph[i][C - 1] = graph[i + 1][C - 1];
		}
		for (int i = C - 1; i > cleanerY; --i) {
			graph[cleanerX - 1][i] = graph[cleanerX - 1][i - 1];
		}

		graph[cleanerX - 1][cleanerY] = graph[cleanerX][cleanerY] = -1;
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (graph[i][j] > 0) {
				ret += graph[i][j];
			}
		}
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}