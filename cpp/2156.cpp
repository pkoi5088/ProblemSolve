#include <iostream>
#include <algorithm>
#define MAX 100001

using namespace std;

int podo[MAX] = { 0 };
int dp[MAX] = { 0 };


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> podo[i];
	dp[1] = podo[1];
	dp[2] = podo[1] + podo[2];

	for (int i = 3; i <= n; i++) {
		dp[i] = max(max(dp[i - 2] + podo[i], dp[i - 3] + podo[i - 1] + podo[i]), dp[i - 1]);
	}

	cout << dp[n];
	return 0;
}