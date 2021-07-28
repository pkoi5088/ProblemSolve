#include <iostream>
#include <cstring>
#define MAX 50000
#define endl '\n'

using namespace std;

int train[MAX], psum[MAX], dp[3][MAX];
int N, M;

int getPsum(int l, int r) {
	if (l == r) return train[r];
	if (l == 0) return psum[r];
	return psum[r] - psum[l - 1];
}

void solve() {
	memset(dp, 0, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> train[i];
	psum[0] = train[0];
	for (int i = 1; i < N; ++i)
		psum[i] = psum[i - 1] + train[i];
	cin >> M;
	dp[0][M - 1] = getPsum(0, M - 1);
	for (int i = M; i < N; ++i) {
		dp[0][i] = max(dp[0][i - 1], getPsum(i - M + 1, i));
	}
	dp[1][M + 1] = getPsum(0, 2 * M - 1);
	for (int i = M + 2; i < N; ++i) {
		dp[1][i] = max(dp[1][i - 1], dp[0][i - M] + getPsum(i - M + 1, i));
	}
	dp[2][M + 3] = getPsum(0, 2 * M + 1);
	for (int i = M + 4; i < N; ++i) {
		dp[2][i] = max(dp[2][i - 1], dp[1][i - M] + getPsum(i - M + 1, i));
	}
	cout << dp[2][N - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
