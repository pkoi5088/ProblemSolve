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

int cnt = 0, N, r, c;

void dfs(int x, int y, int length) {
	if (!(r >= x && r < x + length && c >= y && c < y + length)) {
		cnt += length * length;
	}
	else if (x == r && y == c) {
		cout << cnt;
	}
	else {
		dfs(x, y, length / 2);
		dfs(x, y + length / 2, length / 2);
		dfs(x + length / 2, y, length / 2);
		dfs(x + length / 2, y + length / 2, length / 2);
	}
}


void solve() {
	cin >> N >> r >> c;
	dfs(0, 0, pow(2, N));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
