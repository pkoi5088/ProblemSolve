#include <iostream>
#include <algorithm>
#define MAX 1001
#define P_MAX 10001

using namespace std;

int dp[MAX] = { -1 };
int price[P_MAX] = { -1 };

int solve(int& N) {
	dp[1] = price[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = price[i];
		for (int j = 0; j <= i; j++) {
			dp[i] = max(dp[i - j] + price[j], dp[i]);
		}
	}
	return dp[N];
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> price[i];
	}
	dp[0] = price[0] = 0;
	cout << solve(N);
	return 0;
}