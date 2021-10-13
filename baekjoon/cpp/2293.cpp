#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	int arr[101];
	int dp[10001] = { 0 };

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j + arr[i] <= k; j++)
			if (dp[j])
				dp[j + arr[i]] += dp[j];

	cout << dp[k] << endl;
	return 0;
}
