#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
#define MAX 4

using namespace std;

/*
	https://www.acmicpc.net/problem/14391
*/

int arr[MAX][MAX], state[MAX];
int N, M, ret = -1;

void dfs(int idx) {
	if (idx >= N) {
		//0가로 1세로
		bool visit[MAX][MAX] = { false, };
		int s = 0;

		//가로계산
		for (int x = 0; x < N; ++x) {
			int y = 0;
			while (y < M) {
				if (visit[x][y] || (state[x] & (1 << y))) {
					y += 1;
					continue;
				}
				int tmp = 0;
				int ny = y;
				while (ny < M && !visit[x][ny] && !(state[x] & (1 << ny))) {
					tmp = tmp * 10 + arr[x][ny];
					visit[x][ny] = true;
					ny += 1;
				}
				s += tmp;
				y = ny;
			}
		}

		//세로계산
		for (int x = 0; x < N; ++x) {
			int y = 0;
			while (y < M) {
				if (visit[x][y] || !(state[x] & (1 << y))) {
					y += 1;
					continue;
				}
				int tmp = 0;
				int nx = x;
				while (nx < N && !visit[nx][y] && (state[nx] & (1 << y))) {
					tmp = tmp * 10 + arr[nx][y];
					visit[nx][y] = true;
					nx += 1;
				}
				s += tmp;
			}
		}
		ret = max(ret, s);
	}
	else {
		for (int i = 0; i < (1 << M); ++i) {
			state[idx] = i;
			dfs(idx + 1);
		}
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; ++j) {
			arr[i][j] = tmp[j] - '0';
		}
	}
	dfs(0);
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}