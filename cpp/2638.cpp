#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void solve() {
	int N, M, cnt1 = 0, time = 0;
	cin >> N >> M;
	vector<vector<int>> graph;
	graph.resize(N);
	for (int i = 0; i < N; ++i)
		graph[i].resize(M);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> graph[i][j];
			if (graph[i][j])
				++cnt1;
		}
	}

	queue<pair<int, int>> q;
	//-1 방문한 외부공기, 0 방문안한 외부공기, 1 방문안한 치즈, 2~N 방문한 치즈
	while (cnt1 != 0) {
		//문제에서 설명한 맨 가장자리라는 것이 네 변을 말하는지 네 꼭지점을 말하는지 모르겠음
		q.push({ 0,0 });
		graph[0][0] = -1;

		while (!q.empty()) {
			int x = q.front().first, y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (graph[nx][ny] == 0) {
						q.push({ nx,ny });
						graph[nx][ny] = -1;
					}
					else if (graph[nx][ny] >= 1) {
						graph[nx][ny] += 1;
					}
				}
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (graph[i][j] == -1) {
					graph[i][j] = 0;
				}
				else if (graph[i][j] >= 3) {
					graph[i][j] = 0;
					cnt1 -= 1;
				}
				else if (graph[i][j]) {
					graph[i][j] = 1;
				}
			}
		}
		time += 1;
	}
	cout << time;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
