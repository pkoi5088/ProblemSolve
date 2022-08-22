#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/20058
*/

int N, Q, totalSize;
vector<vector<int>> A;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

void rotate(int x, int y, int size, int goal) {
	if (size == goal) {
		vector<vector<int>> tmp(size, vector<int>(size));
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				tmp[j][size - i - 1] = A[x + i][y + j];
			}
		}
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				A[x + i][y + j] = tmp[i][j];
			}
		}
	}
	else {
		rotate(x, y, size / 2, goal);
		rotate(x + size / 2, y, size / 2, goal);
		rotate(x, y + size / 2, size / 2, goal);
		rotate(x + size / 2, y + size / 2, size / 2, goal);
	}
}

void melt() {
	vector<vector<int>> tmp(totalSize, vector<int>(totalSize, 0));
	for (int i = 0; i < totalSize; ++i) {
		for (int j = 0; j < totalSize; ++j) {
			if (A[i][j] == 0) continue;

			int cnt = 0;
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx < 0 || nx >= totalSize || ny < 0 || ny >= totalSize) continue;
				if (A[nx][ny] > 0) cnt += 1;
			}
			if (cnt < 3) tmp[i][j] += 1;
		}
	}

	for (int i = 0; i < totalSize; ++i) {
		for (int j = 0; j < totalSize; ++j) {
			A[i][j] -= tmp[i][j];
		}
	}
}

void solve() {
	cin >> N >> Q;
	totalSize = pow(2, N);
	A.resize(totalSize, vector<int>(totalSize));
	for (int i = 0; i < totalSize; ++i) {
		for (int j = 0; j < totalSize; ++j) {
			cin >> A[i][j];
		}
	}
	
	while (Q--) {
		int L;
		cin >> L;
		rotate(0, 0, totalSize, pow(2, L));
		melt();
	}

	int retIce = 0, retSize = 0;
	for (int i = 0; i < totalSize; ++i) {
		for (int j = 0; j < totalSize; ++j) {
			retIce += A[i][j];
		}
	}

	for (int i = 0; i < totalSize; ++i) {
		for (int j = 0; j < totalSize; ++j) {
			if (A[i][j] == 0) continue;
			int cnt = 1;
			queue<pair<int, int>> q;
			q.push({ i,j });
			A[i][j] = 0;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx >= totalSize || ny < 0 || ny >= totalSize || A[nx][ny] == 0) continue;
					q.push({ nx,ny });
					A[nx][ny] = 0;
					cnt += 1;
				}
			}
			retSize = max(retSize, cnt);
		}
	}
	cout << retIce << endl << retSize;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}