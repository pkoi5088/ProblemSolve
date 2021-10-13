#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

vector<vector<bool>> v;
int cnt[2] = { 0 };

bool check(int x, int y, int length) {
	bool b = v[x][y];
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			if (b ^ v[i][j])
				return false;
		}
	}
	return true;
}

void dfs(int x, int y, int length) {
	if (check(x, y, length)) {
		cnt[v[x][y]] += 1;
	}
	else {
		dfs(x, y, length / 2);
		dfs(x, y + length / 2, length / 2);
		dfs(x + length / 2, y, length / 2);
		dfs(x + length / 2, y + length / 2, length / 2);
	}
}

void solve() {
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		v[i].resize(N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;
			v[i][j] = x == 0 ? false : true;
		}
	}

	dfs(0, 0, N);
	cout << cnt[0] << endl << cnt[1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
