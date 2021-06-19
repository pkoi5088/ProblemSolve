#include <iostream>
#include <queue>
#define MAX 50
#define endl '\n'

using namespace std;

void solve() {
	int map[MAX][MAX] = { 0 }, visit[MAX][MAX] = { 0 };
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
	int M, N, K, cnt = 0;
	cin >> M >> N >> K;
	while (K--) {
		int X, Y;
		cin >> X >> Y;
		map[Y][X] = 1;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (map[i][j] == 1 && visit[i][j] == 0) {
				cnt += 1;
				queue<pair<int, int>> q;
				q.push({ i,j });
				visit[i][j] = 1;
				while (!q.empty()) {
					int x = q.front().first, y = q.front().second;
					q.pop();
					for (int l = 0; l < 4; ++l) {
						int nx = x + dx[l], ny = y + dy[l];
						if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 1 && visit[nx][ny] == 0) {
							q.push({ nx,ny });
							visit[nx][ny] = 1;
						}
					}
				}
			}
		}
	}
	cout << cnt << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
