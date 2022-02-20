#include <iostream>
#include <cstring>
#define MAX_K 101
#define MAX_T 10001
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/2624
*/

long long dp[MAX_K][MAX_T];
pair<int, int> coin[MAX_K];
int T, k;

void solve() {
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	cin >> T >> k;
	for (int i = 1; i <= k; ++i)
		cin >> coin[i].first >> coin[i].second;

	//몇번째 동전을 사용할지
	for (int i = 1; i <= k; ++i) {
		int value = coin[i].first, quantity = coin[i].second;
		for (int now = 0; now <= T; ++now) {
			for (int price = 0; price <= value * quantity; price += value) {
				if (now - price < 0) break;
				dp[i][now] += dp[i - 1][now - price];
			}
		}
	}
	cout << dp[k][T];
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}