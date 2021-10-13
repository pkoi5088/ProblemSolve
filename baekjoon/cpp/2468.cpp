#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph, dp;
vector<vector<bool>> visit;
int N, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

int bfs(int num) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (graph[i][j] <= num || dp[i][j] != -1) {
				continue;
			}
			queue<pair<int, int>> q;
			q.push({ i,j });
			cnt += 1;
			visit[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				dp[x][y] = cnt;
				for (int l = 0; l < 4; l++) {
					int nx = x + dx[l], ny = y + dy[l];
					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						if (graph[nx][ny] > num && visit[nx][ny] == false) {
							q.push({ nx,ny });
							visit[nx][ny] = true;
						}
					}
				}
			}
		}
	}
	return cnt;
}

void reset() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
			dp[i][j] = -1;
		}
	}
}

int solve() {
	int result = -1;
	cin >> N;
	graph.resize(N);
	dp.resize(N);
	visit.resize(N);
	for (int i = 0; i < N; i++) {
		graph[i].resize(N);
		dp[i].resize(N, -1);
		visit[i].resize(N, false);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	for (int num = 0; num <= 100; num++) {
		result = max(result, bfs(num));
		reset();
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}