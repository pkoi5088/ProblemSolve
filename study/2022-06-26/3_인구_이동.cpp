#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#define endl '\n'
#define MAX 50

using namespace std;

/*
	https://www.acmicpc.net/problem/16234
*/

int N, L, R;
int A[MAX][MAX], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
bool check[MAX][MAX];

bool function() {
	bool ret = false;
	vector<vector<pair<int, int>>> v;
	memset(check, false, sizeof(check));
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (check[i][j]) continue;
			vector<pair<int, int>> tmp;
			queue<pair<int, int>> q;
			q.push({ i,j });
			check[i][j] = true;
			tmp.push_back({ i,j });
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();

				for (int k = 0; k < 4; ++k) {
					int nx = x + dx[k], ny = y + dy[k];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N || check[nx][ny]) continue;
					if (abs(A[x][y] - A[nx][ny]) >= L && abs(A[x][y] - A[nx][ny]) <= R) {
						q.push({ nx,ny });
						check[nx][ny] = true;
						tmp.push_back({ nx,ny });
					}
				}
			}

			if (tmp.size() >= 2) {
				ret = true;
				v.push_back(tmp);
			}
		}
	}

	for (int i = 0; i < v.size(); ++i) {
		int S = 0;
		for (int j = 0; j < v[i].size(); ++j) {
			int x = v[i][j].first, y = v[i][j].second;
			S += A[x][y];
		}
		for (int j = 0; j < v[i].size(); ++j) {
			int x = v[i][j].first, y = v[i][j].second;
			A[x][y] = S / v[i].size();
		}
	}
	return ret;
}

void solve() {
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}

	int ret = 0;
	while (function()) {
		ret += 1;
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