#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> st, dp;

int main() {
	int N;
	cin >> N;
	st.resize(N + 1, -1);
	dp.resize(N + 1, -1);
	st[0] = dp[0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> st[i];
	dp[1] = st[1];
	dp[2] = st[1] + st[2];
	dp[3] = max(st[1], st[2]) + st[3];

	for (int i = 4; i <= N; i++)
		dp[i] = max(dp[i - 2], dp[i - 3] + st[i - 1]) + st[i];

	cout << dp[N];
	return 0;
}