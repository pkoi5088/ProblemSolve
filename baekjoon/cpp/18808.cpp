#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 40

using namespace std;

/*
	https://www.acmicpc.net/problem/18808
*/

class Sticker {
public:
	int _N, _M;
	vector<vector<int>> arr;

	void init() {
		cin >> _N >> _M;
		arr.resize(_N);
		for (int i = 0; i < _N; ++i) {
			arr[i].resize(_M);
		}

		for (int i = 0; i < _N; ++i) {
			for (int j = 0; j < _M; ++j) {
				cin >> arr[i][j];
			}
		}
	}

	void rotate() {
		vector<vector<int>> tmp;
		tmp.resize(_M);
		for (int i = 0; i < _M; ++i) {
			tmp[i].resize(_N);
		}

		for (int i = 0; i < _N; ++i) {
			for (int j = 0; j < _M; ++j) {
				tmp[j][_N - i - 1] = arr[i][j];
			}
		}
		swap(_N, _M);
		arr = tmp;
	}
};

int N, M, K, ret = 0;
vector<Sticker> v;
int board[MAX][MAX] = { 0, };

//board에 idx를 붙일수 있는가
bool check(int x, int y, int idx) {
	for (int i = 0; i < v[idx]._N; ++i) {
		for (int j = 0; j < v[idx]._M; ++j) {
			if (board[x + i][y + j] == 1 && v[idx].arr[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}

//board에 idx를 붙인다.
void attach(int x, int y, int idx) {
	for (int i = 0; i < v[idx]._N; ++i) {
		for (int j = 0; j < v[idx]._M; ++j) {
			board[x + i][y + j] += v[idx].arr[i][j];
		}
	}
}

//idx번 스티커를 붙인다
void dfs(int idx) {
	if (idx >= K) {
		int tmp = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (board[i][j]) tmp += 1;
			}
		}
		ret = max(ret, tmp);
		return;
	}
	//붙인적이 있는가?
	bool flag = false;
	for (int l = 0; l < 4; ++l) {
		for (int i = 0; i < N - v[idx]._N + 1; ++i) {
			for (int j = 0; j < M - v[idx]._M + 1; ++j) {
				if (check(i, j, idx)) {
					attach(i, j, idx);
					dfs(idx + 1);
					return;
				}
			}
		}
		v[idx].rotate();
	}
	dfs(idx + 1);
}

void solve() {
	cin >> N >> M >> K;
	v.resize(K);
	for (int i = 0; i < K; ++i) {
		v[i].init();
	}
	dfs(0);
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}