#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define endl '\n'
#define MAX 300

using namespace std;

/*
	https://www.acmicpc.net/problem/2573
*/

int N, M;
int arr[MAX][MAX], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
bool visit[MAX][MAX];

bool check() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] != 0)
				return true;
		}
	}
	return false;
}

int finish() {
	memset(visit, false, sizeof(visit));
	int ret = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] != 0 && visit[i][j] == false) {
				ret += 1;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; ++k) {
						int nx = x + dx[k], ny = y + dy[k];
						if (arr[nx][ny] == 0 || visit[nx][ny]) continue;
						q.push({ nx,ny });
						visit[nx][ny] = true;
					}
				}
			}
		}
	}
	return ret;
}

void melting() {
	int tmp[MAX][MAX] = { 0, };
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] != 0) {
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k], ny = j + dy[k];
					if (arr[nx][ny] == 0)
						tmp[i][j] += 1;
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			arr[i][j] -= tmp[i][j];
			if (arr[i][j] < 0)
				arr[i][j] = 0;
		}
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	int ret = 0;
	while (check()) {
		if (finish() >= 2) {
			cout << ret;
			return;
		}
		ret += 1;
		melting();
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