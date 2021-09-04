#include <iostream>
#define MAX 50
#define endl '\n'

using namespace std;

//0:청소안됨, 1:벽, 2:청소됨
int board[MAX][MAX];
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
int N, M;

class Robot {
public:
	int x, y, dir, count;
	Robot(int ix, int iy,int id) {
		x = ix, y = iy, dir = id;
		count = 0;
	}

	bool search() {
		int d = (dir - 1 + 4) % 4;
		int nx = x + dx[d], ny = y + dy[d];
		return (board[nx][ny] == 0);
	}

	bool searchBack() {
		int nx = x - dx[dir], ny = y - dy[dir];
		return (board[nx][ny] != 1);
	}

	void clean() {
		if (board[x][y] == 0)
			count++;
		board[x][y] = 2;
	}

	void rotate() {
		dir = (dir - 1 + 4) % 4;
	}

	void go() {
		x += dx[dir], y += dy[dir];
	}

	void back() {
		x -= dx[dir], y -= dy[dir];
	}
};

void solve() {
	cin >> N >> M;
	int R, C, D, count = 0, state = 1;
	cin >> R >> C >> D;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> board[i][j];
		}
	}
	Robot robot(R, C, D);
	while (true) {
		if (state == 1) {
			robot.clean();
			state = 2;
		}
		else {
			if (robot.search()) {
				robot.rotate();
				robot.go();
				state = 1;
			}
			else {
				if (count == 4) {
					if (robot.searchBack()) {
						robot.back();
						count = 0;
					}
					else {
						break;
					}
				}
				else {
					robot.rotate();
					count++;
				}
			}
		}
		cout << robot.x << ' ' << robot.y << ' ' << robot.dir << endl;
	}
	cout << robot.count;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
