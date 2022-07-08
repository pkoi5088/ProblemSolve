#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 102

using namespace std;

/*
	https://www.acmicpc.net/problem/5547
*/

int arr[MAX][MAX] = { 0, };
int W, H;
int dx[2][6] = { {-1,-1,0,0,1,1}, { -1,-1,0,0,1,1 } }, dy[2][6] = { { -1,0,-1,1,-1,0 } ,{ 0,1,-1,1,0,1 } };

void solve() {
	cin >> W >> H;
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j) {
			cin >> arr[i][j];
		}
	}

	queue<pair<int, int>> q;
	q.push({ 0,0 });
	arr[0][0] = -1;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();

		for (int k = 0; k < 6; ++k) {
			int nx = x + dx[x % 2][k], ny = y + dy[x % 2][k];
			if (nx<0 || nx>H+1 || ny<0 || ny>W+1 || arr[nx][ny] != 0) continue;
			q.push({ nx,ny });
			arr[nx][ny] = -1;
		}
	}

	int ret = 0;
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j) {
			if (arr[i][j] == 1) {
				int count = 0;
				for (int k = 0; k < 6; ++k) {
					int nx = i + dx[i % 2][k], ny = j + dy[i % 2][k];
					if (nx<0 || nx>H+1 || ny<0 || ny>W+1 || arr[nx][ny] != -1) continue;
					count += 1;
				}
				ret += count;
			}
		}
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}