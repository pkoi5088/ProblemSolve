#include <iostream>
#include <queue>
#define endl '\n'
#define MAX 100

using namespace std;

/*
	https://www.acmicpc.net/problem/2636
*/

int N, M;
int arr[MAX][MAX], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
bool check[MAX][MAX] = { false, };

bool finishCheck() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 1) return 1;
		}
	}
	return 0;
}

int function() {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	check[0][0] = true;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		
		for (int k = 0; k < 4; ++k) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] || check[nx][ny])
				continue;
			q.push({ nx,ny });
			check[nx][ny] = true;
		}
	}

	int ret = 0;
	for (int i = 1; i < N - 1; ++i) {
		for (int j = 1; j < M - 1; ++j) {
			if (arr[i][j] == 1) {
				ret += 1;
				bool flag = false;
				for (int k = 0; k < 4; ++k) {
					int nx = i + dx[k], ny = j + dy[k];
					if (check[nx][ny]) {
						flag = true;
					}
				}
				if (flag) arr[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			check[i][j] = false;
		}
	}
	return ret;
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
		}
	}

	int ret = 0, rest = 0;
	while (finishCheck()) {
		ret += 1;
		rest = function();
	}
	cout << ret << endl << rest;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}