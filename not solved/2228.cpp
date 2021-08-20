#include <iostream>
#include <cstring>
#define MAX 100
#define INF -1000000009
#define endl '\n'

using namespace std;

int dp[MAX][MAX / 2 + 1], arr[MAX];
int N, M;

int getDP(int n, int m) {
	if (n < 0 || m <= 0 || 2 * m - 1 > n + 1) return INF;
	
	int& ret = dp[n][m];
	if (ret != INF) return ret;

	if (m == 1) {
		ret = max(arr[n], getDP(n - 1, m) + arr[n]);
	}
	else {
		ret = max(getDP(n - 1, m) + arr[n], getDP(n - 2, m - 1) + arr[n]);
	}
	ret = max(ret, getDP(n - 1, m));
	return ret;
}

void solve() {
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX / 2 + 1; ++j)
			dp[i][j] = INF;

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];

	cout << getDP(N - 1, M) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
