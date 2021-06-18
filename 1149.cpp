#include <iostream>
#define MAX 1001

using namespace std;

int h[3][MAX], dp[3][MAX];

int min(int& a, int& b) {
	return a < b ? a : b;
}

int min2(int& a, int& b, int& c) {
	return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int main() {
	int N;
	cin >> N;
	h[0][0] = h[1][0] = h[2][0]
		= dp[0][0] = dp[1][0] = dp[2][0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> h[0][i] >> h[1][i] >> h[2][i];
	dp[0][1] = h[0][1];
	dp[1][1] = h[1][1];
	dp[2][1] = h[2][1];

	for (int i = 2; i <= N; i++) {
		dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + h[0][i];
		dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + h[1][i];
		dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + h[2][i];
	}

	cout << min2(dp[0][N], dp[1][N], dp[2][N]);
	return 0;
}