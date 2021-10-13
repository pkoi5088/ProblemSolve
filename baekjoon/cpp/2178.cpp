#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#define MAX 101

using namespace std;

int map[MAX][MAX] = { 0 };

int bfs(int N, int M) {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == N && y == M)
			return map[x][y];

		if (map[x + 1][y] == 1) {
			q.push({ x + 1,y });
			map[x + 1][y] = map[x][y] + 1;
		}
		if (map[x][y + 1] == 1) {
			q.push({ x,y + 1 });
			map[x][y + 1] = map[x][y] + 1;
		}
		if (map[x][y - 1] == 1) {
			q.push({ x,y - 1 });
			map[x][y - 1] = map[x][y] + 1;
		}
		if (map[x - 1][y] == 1) {
			q.push({ x - 1,y });
			map[x - 1][y] = map[x][y] + 1;
		}
	}
	return -1;
}

int main() {
	int N, M;
	string input;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		cin.ignore();
		for (int j = 0; j < M; j++)
			map[i][j + 1] = (int)input[j] - 48;
	}
	for (int i = 0; i <= N; i++)
		map[0][i] = 2;
	for (int i = 0; i <= M; i++)
		map[i][0] = 2;

	cout << bfs(N, M);
	return 0;
}