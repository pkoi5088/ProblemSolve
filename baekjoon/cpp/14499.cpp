#include <iostream>
#define MAX 20
#define endl "\n"

using namespace std;

void moveNorth(int* dice) {
	int tmp = dice[0];
	dice[0] = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[1];
	dice[1] = tmp;
}

void moveSouth(int* dice) {
	int tmp = dice[0];
	dice[0] = dice[1];
	dice[1] = dice[5];
	dice[5] = dice[4];
	dice[4] = tmp;
}

void moveEast(int* dice) {
	int tmp = dice[0];
	dice[0] = dice[3];
	dice[3] = dice[5];
	dice[5] = dice[2];
	dice[2] = tmp;
}

void moveWest(int* dice) {
	int tmp = dice[0];
	dice[0] = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[3];
	dice[3] = tmp;
}

void solve() {
	int map[MAX][MAX], dice[6] = { 0 };
	int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> map[i][j];
		}
	}

	while (K--) {
		int dir, nx, ny;
		cin >> dir;
		dir -= 1;
		nx = x + dx[dir], ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		x = nx, y = ny;
		if (dir == 0) moveEast(dice);
		else if (dir == 1) moveWest(dice);
		else if (dir == 2) moveNorth(dice);
		else if (dir == 3) moveSouth(dice);
		if (map[x][y] == 0) map[x][y] = dice[5];
		else {
			dice[5] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[0] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}