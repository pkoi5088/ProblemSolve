#include <iostream>
#include <algorithm>
#define MAX 501

using namespace std;

int tri[MAX][MAX] = { -1 };
int dp[MAX][MAX] = { -1 };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> tri[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
		dp[n][i] = tri[n][i];

	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + tri[i][j];
		}
	}

	cout << dp[1][1];
	return 0;
}