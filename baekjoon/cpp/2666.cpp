#include <iostream>
#include <cstring>
#define MAX 21
#define endl '\n'

using namespace std;

int dp[MAX][MAX], arr[MAX];
int startL, startR, N, M;

int getDP(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];

	//기저사례
	if (l == M || r == M) return dp[l][r] = 0;

	int now = max(l, r);
	int locL = (l == 0 ? startL : arr[l]), locR = (r == 0 ? startR : arr[r]);
	int distL = abs(locL - arr[now + 1]), distR = abs(locR - arr[now + 1]);
	return dp[l][r] = min(getDP(now + 1, r) + distL, getDP(l, now + 1) + distR);
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> startL >> startR >> M;
	for (int i = 1; i <= M; ++i)
		cin >> arr[i];
	cout << getDP(0, 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
