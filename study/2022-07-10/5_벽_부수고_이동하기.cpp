#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define endl '\n'
#define MAX 1000

using namespace std;

/*
	https://www.acmicpc.net/problem/2206
*/

int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int dist[MAX][MAX][2];
vector<string> arr;
int N, M;

int min(int a, int b) {
	if (a == -1) return b;
	else if (b == -1) return a;
	return a < b ? a : b;
}

void solve() {
	cin >> N >> M;
	arr.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		for (int j = 0; j < M; ++j) {
			dist[i][j][0] = dist[i][j][1] = -1;
		}
	}

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{1,0} });
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second;
		int d = q.front().second.first, flag = q.front().second.second;
		q.pop();
		
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

			if (flag) {
				if (arr[nx][ny] == '1' || dist[nx][ny][flag] != -1) continue;
				q.push({ {nx,ny},{d + 1,flag} });
				dist[nx][ny][flag] = d + 1;
			}
			else {
				if (arr[nx][ny] == '1') {
					q.push({ { nx,ny }, { d + 1,1 } });
					dist[nx][ny][1] = d + 1;
				}
				else {
					if (dist[nx][ny][flag] != -1)
						continue;
					q.push({ { nx,ny }, { d + 1,flag } });
					dist[nx][ny][flag] = d + 1;
				}
			}
		}
	}

	int ret = min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}