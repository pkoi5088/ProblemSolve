#include <iostream>
#include <algorithm>

using namespace std;

int** map;

int main() {
	int N, M;
	cin >> N >> M;

	map = new int*[N + 1];
	for (int i = 0; i <= N; i++)
		map[i] = new int[M + 1];
	for (int i = 0; i <= N; i++)
		map[i][0] = 0;
	for (int i = 0; i <= M; i++)
		map[0][i] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			map[i][j] = max(map[i - 1][j - 1], max(map[i - 1][j], map[i][j - 1])) + map[i][j];
		}
	}

	cout << map[N][M];
	return 0;
}