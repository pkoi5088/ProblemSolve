#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#define MAX 2000
#define endl '\n'

using namespace std;

int num[2][MAX], dp[MAX][MAX];
int N;

int pick(int a, int b) {
	if (a == N || b == N) return 0;
	if (dp[a][b] != -1) return dp[a][b];
	dp[a][b] = 0;
	dp[a][b] = max(dp[a][b], pick(a + 1, b));
	dp[a][b] = max(dp[a][b], pick(a + 1, b + 1));
	if (num[0][a] > num[1][b]) {
		dp[a][b] = max(dp[a][b], pick(a, b + 1) + num[1][b]);
	}
	return dp[a][b];
}

void solve() {
	cin >> N;
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < N; ++i) {
			cin >> num[k][i];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << pick(0, 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
