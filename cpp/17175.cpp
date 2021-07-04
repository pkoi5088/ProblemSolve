#include <iostream>

using namespace std;

int dp[51];

int main(void) {

	dp[0] = dp[1] = 1;
	for (int i = 2; i <= 50; i++) {
		dp[i] = 1;
		dp[i] += (dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007) % 1000000007;
	}

	int n;
	cin >> n;
	cout << dp[n] % 1000000007;
	return 0;
}