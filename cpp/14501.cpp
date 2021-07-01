#include <iostream>
#include <string.h>

using namespace std;

int t[16] = { 0 };
int m[16] = { 0 };
int dp[16];

int max(int& a, int&& b) {
	return a > b ? a : b;
}

int max(int& a, int& b) {
	return a > b ? a : b;
}

int main() {
	int N;
	cin >> N;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++)
		cin >> t[i] >> m[i];

	for (int i = N; i >= 1; i--) {
		if (i + t[i] > N + 1) {
			if (i == N)
				dp[i] = 0;
			else
				dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[i + t[i]] + m[i]);
		}
	}

	cout << dp[1];
	return 0;
}