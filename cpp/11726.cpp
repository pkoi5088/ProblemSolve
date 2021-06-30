#include <iostream>
#define MAX 1001

using namespace std;

int dp[MAX];

int main() {
	int N;
	cin >> N;
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	cout << dp[N];
	return 0;
}