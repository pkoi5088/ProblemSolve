#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int sticker[2][MAX], dp[2][MAX];

int max(int& a, int& b) {
	return a > b ? a : b;
}

int f(int& N) {
	dp[0][1] = sticker[0][1];
	dp[1][1] = sticker[1][1];
	for (int i = 2; i <= N; i++) {
		dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
		dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
	}
	return dp[0][N] > dp[1][N] ? dp[0][N] : dp[1][N];
}

int main() {
	int T, N;
	cin >> T;
	sticker[0][0] = sticker[1][0] = dp[0][0] = dp[1][0] = 0;
	for (int i = 0; i < T; i++) {
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> sticker[0][i];
		for (int i = 1; i <= N; i++)
			cin >> sticker[1][i];
		cout << f(N) << endl;
	}
	return 0;
}