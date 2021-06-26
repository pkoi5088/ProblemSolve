#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int graph[100][100][2] = { 0 };
bool visit[100][100][2] = { false };
int N, result[2] = { 0 }, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void bfs(int type) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (visit[i][j][type] == true)
				continue;
			result[type] += 1;
			queue<pair<int, int>> q;
			q.push({ i,j });
			visit[i][j][type] = true;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int l = 0; l < 4; l++) {
					int nx = x + dx[l], ny = y + dy[l];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						if (graph[x][y][type] == graph[nx][ny][type] && visit[nx][ny][type] == false) {
							visit[nx][ny][type] = true;
							q.push({ nx,ny });
						}
					}
				}
			}
		}
	}
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'R') {
				graph[i][j][0] = graph[i][j][1] = 0;
			}
			else if (s[j] == 'G') {
				graph[i][j][0] = 1;
				graph[i][j][1] = 0;
			}
			else {
				graph[i][j][0] = graph[i][j][1] = 2;
			}
		}
	}
	bfs(0); bfs(1);
	cout << result[0] << ' ' << result[1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}