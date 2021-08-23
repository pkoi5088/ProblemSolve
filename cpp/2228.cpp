#include <iostream>
#define MAX_N 101
#define MAX_M 51
#define MIN -1000000009
#define endl '\n'

using namespace std;

int dp[MAX_N][MAX_M], arr[MAX_N] = { 0, };
int N, M;

int getDP(int n, int m) {
	if (n <= 0 || m < 0) return MIN;

	int& ret = dp[n][m];
	if (ret != MIN) return ret;

	//기저사례
	if (2 * m - 1 > n) return ret = MIN - 1;

	//선택 안했을 때
	ret = getDP(n - 1, m);

	//선택할 때
	for (int i = 1; i <= n; ++i)
		ret = max(ret, getDP(i - 2, m - 1) + arr[n] - arr[i - 1]);
	return ret;
}

void solve() {
	for (int i = 0; i < MAX_N; ++i)
		for (int j = 0; j < MAX_M; ++j)
			dp[i][j] = MIN;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	dp[1][1] = arr[1];
	for (int i = 2; i <= N; ++i)
		dp[i][1] = max(dp[i - 1][1] + arr[i] - arr[i - 1], arr[i] - arr[i - 1]);
	for (int i = 2; i <= N; ++i)
		dp[i][1] = max(dp[i][1], dp[i - 1][1]);

	cout << getDP(N, M) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
