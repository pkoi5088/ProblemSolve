#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#define INF 65

using namespace std;

vector<string> board;
string answer[2] = { "WBWBWBWB","BWBWBWBW" };
int N, M;

int solve() {
	int result = INF;
	cin >> N >> M;
	board.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	for (int startX = 0; startX < N - 7; startX++) {
		for (int startY = 0; startY < M - 7; startY++) {
			int a = 0, b = 0;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (answer[i % 2][j] != board[startX + i][startY + j]) {
						a += 1;
					}
					if (answer[!(i % 2)][j] != board[startX + i][startY + j]) {
						b += 1;
					}
				}
			}
			result = min(result, a);
			result = min(result, b);
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