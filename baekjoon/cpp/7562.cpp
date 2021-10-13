#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

class Node {
public:
	int x, y, dist;
	Node(int ix, int iy, int id) :x(ix), y(iy), dist(id) {};
};

bool visit[300][300] = { false };
int dx[8] = { -2,-2,-1,-1,1,1,2,2 }, dy[8] = { -1,1,-2,2,-2,2,-1,1 };

void reset(int I) {
	for (int i = 0; i < I; i++) {
		for (int j = 0; j < I; j++) {
			visit[i][j] = false;
		}
	}
}

int solve() {
	int I;
	cin >> I;
	int startX, startY, goalX, goalY;
	cin >> startX >> startY >> goalX >> goalY;

	reset(I);
	queue<Node> q;
	q.push(Node(startX, startY, 0));
	visit[startX][startY] = true;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dist = q.front().dist;
		q.pop();
		if (x == goalX && y == goalY)
			return dist;
		for (int d = 0; d < 8; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx >= 0 && nx < I && ny >= 0 && ny < I) {
				if (visit[nx][ny] == false) {
					visit[nx][ny] = true;
					q.push(Node(nx, ny, dist + 1));
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		cout << solve() << '\n';
	return 0;
}