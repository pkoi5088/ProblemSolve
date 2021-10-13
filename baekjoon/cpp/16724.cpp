#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#define MAX 1000
#define endl '\n'

using namespace std;

string map[MAX];
//0: 탐색안함, 1: 탐색중, 2:safe zone이 존재
int visit[MAX][MAX] = { 0 };
int N, M;

void dfs(int x, int y, int& result) {
	visit[x][y] = 1;
	int nx = x, ny = y;
	switch (map[x][y]) {
	case 'U':
		nx -= 1;
		break;

	case 'D':
		nx += 1;
		break;

	case 'L':
		ny -= 1;
		break;

	case 'R':
		ny += 1;
		break;
	}
	if (visit[nx][ny] == 1) {
		result += 1;
	}
	else if (visit[nx][ny] == 0) {
		dfs(nx, ny, result);
	}
	visit[x][y] = 2;
}

void solve() {
	int result = 0;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> map[i];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (visit[i][j] == 0) {
				dfs(i, j, result);
			}
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
