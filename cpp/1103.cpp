#include <iostream>
#include <cstring>
#define MAX 50
#define endl '\n'

using namespace std;

//cache[x][y]: [x,y]에서 최대 얼만큼 움직일 수 있나
int map[MAX][MAX], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 }, cache[MAX][MAX];
int N, M;
bool visit[MAX][MAX] = { false };

int max(int a, int b) {
	return a > b ? a : b;
}

int getDP(int x, int y) {
	if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] == -1) return 0;
	else if (visit[x][y]) {
		cout << -1;
		exit(0);
	}
	else if (cache[x][y] != -1) return cache[x][y];
	visit[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int nx = x + map[x][y] * dx[i];
		int ny = y + map[x][y] * dy[i];
		cache[x][y] = max(cache[x][y], getDP(nx, ny) + 1);
	}
	visit[x][y] = false;
	return cache[x][y];
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < M; ++j) {
			if (tmp[j] == 'H') {
				map[i][j] = -1;
			}
			else {
				map[i][j] = tmp[j] - '0';
			}
		}
	}

	memset(cache, -1, sizeof(cache));
	cout << getDP(0, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
