#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph, visit;
vector<int> result;
int N, M, K, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void solve() {
	int cnt = 0;
	cin >> N >> M >> K;
	graph.resize(M);
	visit.resize(M);
	for (int i = 0; i < M; i++) {
		graph[i].resize(N);
		visit[i].resize(N, 0);
	}
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++) {
				graph[x][y] = 1;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			int scnt = 0;
			if (graph[i][j] == 1 || visit[i][j] == 1) {
				continue;
			}
			queue<pair<int, int>> q;
			q.push({ i,j });
			visit[i][j] = 1;
			cnt += 1;
			while (!q.empty()) {
				scnt += 1;
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int l = 0; l < 4; l++) {
					int nx = x + dx[l], ny = y + dy[l];
					if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
						if (graph[nx][ny] == 0 && visit[nx][ny] == 0) {
							q.push({ nx,ny });
							visit[nx][ny] = 1;
						}
					}
				}
			}
			result.push_back(scnt);
		}
	}
	sort(result.begin(), result.end());
	cout << cnt << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}