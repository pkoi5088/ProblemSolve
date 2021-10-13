#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

int graph[300][300] = { 0 }, add[300][300] = { 0 };
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
bool visit[300][300] = { false };
int N, M, all = 0;

//0: 빙산이1개, 1: 2개 이상
int check() {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			visit[i][j] = false;
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (graph[i][j] == 0 || visit[i][j])
				continue;
			if (cnt && graph[i][j] != 0)
				return 1;
			cnt += 1;
			queue<pair<int, int>> q;
			q.push({ i,j });
			visit[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				int count = 0;
				for (int l = 0; l < 4; ++l) {
					int nx = x + dx[l], ny = y + dy[l];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						if (graph[nx][ny] == 0) {
							count += 1;
						}
						else if (visit[nx][ny] == false) {
							q.push({ nx,ny });
							visit[nx][ny] = true;
						}
					}
				}
				add[x][y] = count;
			}
		}
	}
	return 0;
}

void solve() {
	int result = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> graph[i][j];
			all += graph[i][j];
		}
	}

	while (all != 0) {
		int c = check();
		if (c == 0) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (graph[i][j] < add[i][j]) {
						all -= graph[i][j];
						graph[i][j] = 0;
					}
					else {
						all -= add[i][j];
						graph[i][j] -= add[i][j];
					}
					add[i][j] = 0;
				}
			}
		}
		else {
			cout << result;
			return;
		}
		result += 1;
	}
	cout << 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
