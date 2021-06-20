#include <iostream>
#define MAX 90
using namespace std;

int main() {
	int N;
	cin >> N;

	long long dp[MAX][2] = { -1 };
	dp[0][0] = 0;
	dp[0][1] = 1;

	for (int i = 1; i < N; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	cout << dp[N - 1][0] + dp[N - 1][1];
	return 0;
}