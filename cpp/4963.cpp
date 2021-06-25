#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int M[50][50] = { 0 };
bool visit[50][50] = { false };
int cnt = 0;
pair<int, int> dir[8] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

void reset() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			M[i][j] = 0;
			visit[i][j] = false;
		}
	}
	cnt = 0;
}

void solve() {
	int w, h;
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> M[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (M[i][j] == 0 || visit[i][j])
					continue;
				cnt += 1;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = true;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int l = 0; l < 8; l++) {
						int nx = x + dir[l].first, ny = y + dir[l].second;
						if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
							if (M[nx][ny] == 1 && visit[nx][ny] == false) {
								q.push({ nx,ny });
								visit[nx][ny] = true;
							}
						}
					}
				}
			}
		}
		cout << cnt << '\n';
		reset();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}