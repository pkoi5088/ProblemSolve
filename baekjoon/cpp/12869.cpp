#include <iostream>
#include <algorithm>
#define endl '\n'
#define MAX 61
#define INF 1000000

using namespace std;

int dp[MAX][MAX][MAX];

int getDP(int a, int b, int c) {
	int& ret = dp[a][b][c];
	if (ret != INF) return ret;

	int nextA = a, nextB = b, nextC = c;

	// 1
	nextA = max(a - 9, 0), nextB = max(b - 3, 0), nextC = max(c - 1, 0);
	ret = min(ret, getDP(nextA, nextB, nextC) + 1);

	// 2
	nextA = max(a - 9, 0), nextB = max(b - 1, 0), nextC = max(c - 3, 0);
	ret = min(ret, getDP(nextA, nextB, nextC) + 1);

	// 3
	nextA = max(a - 3, 0), nextB = max(b - 1, 0), nextC = max(c - 9, 0);
	ret = min(ret, getDP(nextA, nextB, nextC) + 1);

	// 4
	nextA = max(a - 3, 0), nextB = max(b - 9, 0), nextC = max(c - 1, 0);
	ret = min(ret, getDP(nextA, nextB, nextC) + 1);

	// 5
	nextA = max(a - 1, 0), nextB = max(b - 3, 0), nextC = max(c - 9, 0);
	ret = min(ret, getDP(nextA, nextB, nextC) + 1);

	// 6
	nextA = max(a - 1, 0), nextB = max(b - 9, 0), nextC = max(c - 3, 0);
	ret = min(ret, getDP(nextA, nextB, nextC) + 1);

	return ret;
}

void solve() {
	int N;
	int scv[3] = { 0,0,0 };
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; ++j) {
			for (int k = 0; k < MAX; ++k) {
				dp[i][j][k] = INF;
			}
		}
	}
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> scv[i];
	dp[0][0][0] = 0;

	cout << getDP(scv[0], scv[1], scv[2]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}