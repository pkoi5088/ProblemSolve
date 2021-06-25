#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int graph[100][100][100] = { 0 };
bool visit[100][100][100] = { false };
int N, M, H, dx[6] = { 0,0,0,0,-1,1 }, dy[6] = { 0,0,-1,1,0,0 }, dz[6] = { -1,1,0,0,0,0 };

class Node {
public:
	int x, y, z, dist;

	Node(int ix, int iy, int iz, int id) {
		x = ix; y = iy; z = iz; dist = id;
	}
};

int solve() {
	int result = -1;
	queue<Node> q;
	cin >> M >> N >> H;
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> graph[i][j][k];
				if (graph[i][j][k] != 0) {
					visit[i][j][k] = true;
				}
				if (graph[i][j][k] == 1)
					q.push(Node(i, j, k, 0));
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, z = q.front().z, dist = q.front().dist;
		q.pop();
		result = max(result, dist);
		for (int l = 0; l < 6; l++) {
			int nx = x + dx[l], ny = y + dy[l], nz = z + dz[l];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H) {
				if (graph[nx][ny][nz] == 0 && visit[nx][ny][nz] == false) {
					graph[nx][ny][nz] = 1;
					visit[nx][ny][nz] = true;
					q.push(Node(nx, ny, nz, dist + 1));
				}
			}
		}
	}
	for (int k = 0; k < H; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (graph[i][j][k] == 0)
					return -1;
			}
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cout << solve();
	return 0;
}