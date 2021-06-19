#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 10
#define endl '\n'

using namespace std;

//0: 놓을 수 없는 곳, 1: 놓을 수 있는 곳, 2: 비숍이 있는 곳
int check[MAX][MAX] = { 0 };
int dirX[4] = { -1,-1,1,1 }, dirY[4] = { -1,1,-1,1 };
int N, resultB = 0, resultW = 0, length = 0;

bool checkDir(int x,int y) {
	for (int i = 0; i < 4; ++i) {
		int nx = x + dirX[i], ny = y + dirY[i];
		while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
			if (check[nx][ny] == 2)
				return false;
			nx += dirX[i];
			ny += dirY[i];
		}
	}
	return true;
}

void dfs(int x, int y, int type, int& result) {
	//cout << x << ' ' << y << endl;
	length += 1;
	result = max(result, length);
	int nx = x, ny = y + 1;
	for (; nx < N; ++nx) {
		for (; ny < N; ++ny) {
			if ((nx + ny) % 2 != type)
				continue;
			if (check[nx][ny] == 1 && checkDir(nx, ny)) {
				check[nx][ny] = 2;
				dfs(nx, ny, type, result);
				check[nx][ny] = 1;
			}
		}
		ny = 0;
	}
	length -= 1;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> check[i][j];
		}
	}

	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if ((x + y) % 2 != 0)
				continue;
			if (check[x][y] == 1) {
				check[x][y] = 2;
				dfs(x, y, 0, resultB);
				check[x][y] = 1;
			}
		}
	}
	for (int x = 0; x < N; ++x) {
		for (int y = 0; y < N; ++y) {
			if ((x + y) % 2 != 1)
				continue;
			if (check[x][y] == 1) {
				check[x][y] = 2;
				dfs(x, y, 1, resultW);
				check[x][y] = 1;
			}
		}
	}
	cout << resultB + resultW;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
