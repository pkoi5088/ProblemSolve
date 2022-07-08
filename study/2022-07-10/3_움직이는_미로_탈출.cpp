#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/16954
*/

vector<string> arr[9];
int dx[9] = { -1,-1,-1,0,0,0,1,1,1 }, dy[9] = { -1,0,1,-1,0,1,-1,0,1 };
int check[8][8][9] = { 0, };

void solve() {
	for (int i = 0; i < 9; ++i)
		arr[i].resize(8);
	for (int i = 0; i < 8; ++i)
		cin >> arr[0][i];
	for (int i = 1; i < 9; ++i) {
		for (int j = 7; j > 0; j--) {
			arr[i][j] = arr[i - 1][j - 1];
		}
		arr[i][0] = "........";
	}

	queue<pair<pair<int, int>, int>> q;
	q.push({ {7,0},0 });
	check[7][0][0] = 1;
	while (!q.empty()) {
		int x = q.front().first.first, y = q.front().first.second, time = q.front().second;
		q.pop();

		if ((x == 0 && y == 7) || time >= 8 || time > x) {
			cout << 1;
			return;
		}

		vector<string> nextArr = arr[time + 1];
		for (int k = 0; k < 9; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8 || arr[time][nx][ny] == '#' || nextArr[nx][ny] == '#')
				continue;
			q.push({ {nx,ny},time + 1 });
			check[nx][ny][time + 1] = 1;
		}
	}
	cout << 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}