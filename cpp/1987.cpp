#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<string> graph;
int R, C, result = -1, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 }, alpha[26] = { 0 };

void dfs(int x, int y, int dist) {
	result = max(result, dist);
	for (int l = 0; l < 4; l++) {
		int nx = x + dx[l], ny = y + dy[l];
		if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
			if (alpha[graph[nx][ny] - 'A'] == 0) {
				alpha[graph[nx][ny] - 'A'] += 1;
				dfs(nx, ny, dist + 1);
				alpha[graph[nx][ny] - 'A'] -= 1;
			}
		}
	}
}

int solve() {
	cin >> R >> C;
	graph.resize(R);
	for (int i = 0; i < R; i++) {
		cin >> graph[i];
	}
	alpha[graph[0][0] - 'A'] += 1;
	dfs(0, 0, 1);
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}