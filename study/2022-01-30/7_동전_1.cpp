#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2293
*/

void solve() {
	int n, k;
	cin >> n >> k;

	int arr[100],dp[10001] = { 0 };

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j + arr[i] <= k; j++)
			if (dp[j])
				dp[j + arr[i]] += dp[j];
    cout<<dp[k];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}