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

vector<vector<char>> v;
//-1 0 1
int cnt0 = 0, cnt1 = 0, cnt2 = 0;

bool check(int x, int y, int length) {
	char c = v[x][y];
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			if (c != v[i][j])
				return false;
		}
	}
	return true;
}

void dfs(int x, int y, int length) {
	if (check(x, y, length)) {
		if (v[x][y] == '0')
			cnt0 += 1;
		else if (v[x][y] == '1')
			cnt1 += 1;
		else
			cnt2 += 1;
	}
	else {
		dfs(x, y, length / 3);
		dfs(x, y + length / 3, length / 3);
		dfs(x, y + 2 * length / 3, length / 3);
		dfs(x + length / 3, y, length / 3);
		dfs(x + length / 3, y + length / 3, length / 3);
		dfs(x + length / 3, y + 2 * length / 3, length / 3);
		dfs(x + 2 * length / 3, y, length / 3);
		dfs(x + 2 * length / 3, y + length / 3, length / 3);
		dfs(x + 2 * length / 3, y + 2 * length / 3, length / 3);
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
			v[i][j] = x + '0' + 1;
		}
	}

	dfs(0, 0, N);
	cout << cnt0 << endl;
	cout << cnt1 << endl;
	cout << cnt2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
