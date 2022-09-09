#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 100
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/17143
*/

//위0 아래1 오른쪽2 왼쪽3
struct Shark {
	int speed = 0, dir = 0, size = 0;
	Shark(int is, int id, int ins) :speed(is), dir(id), size(ins) {}
};

struct Node {
	int x, y, index;
	Node(int ix, int iy, int idx) :x(ix), y(iy), index(idx) {}
};

int R, C, M;
vector<Shark> sharks;
int map[MAX][MAX];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };

void solve() {
	memset(map, -1, sizeof(map));
	cin >> R >> C >> M;
	for (int i = 0; i < M; ++i) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		map[r - 1][c - 1] = i;
		sharks.push_back(Shark(s, d - 1, z));
	}

	int result = 0;
	for (int king = 0; king < C; ++king) {
		//낚시
		for (int i = 0; i < R; ++i) {
			if (map[i][king] != -1) {
				result += sharks[map[i][king]].size;
				map[i][king] = -1;
				break;
			}
		}

		//상어이동
		queue<Node> q;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				if (map[i][j] != -1) {
					q.push(Node(i, j, map[i][j]));
					map[i][j] = -1;
				}
			}
		}
		while (!q.empty()) {
			int idx = q.front().index;
			int move = sharks[idx].speed, dir = sharks[idx].dir;
			int x = q.front().x, y = q.front().y;
			q.pop();
            if(dir/2==0) move %= (R-1)*2;
            else move %= (C-1)*2;
			while (move--) {
				int nx = x + dx[dir], ny = y + dy[dir];
				if (nx<0 || nx>=R || ny<0 || ny>=C) {
					if (dir / 2) dir = (dir == 2 ? 3 : 2);
					else dir = (dir == 0 ? 1 : 0);
					nx = x + dx[dir], ny = y + dy[dir];
				}
				x = nx; y = ny;
				if (x < 0) x = 0;
				if (x >= R) x = R - 1;
				if (y < 0) y = 0;
				if (y >= C) y = C - 1;
			}
			sharks[idx].dir = dir;
			if (map[x][y] == -1 || sharks[map[x][y]].size < sharks[idx].size) {
				map[x][y] = idx;
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
