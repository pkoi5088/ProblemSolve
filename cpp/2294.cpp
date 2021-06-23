#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

vector<int> coin;
int dp[10001];

void erase() {
	sort(coin.begin(), coin.end());
	coin.erase(unique(coin.begin(), coin.end()), coin.end());
}

int main() {
	int n, k, in;
	cin >> n >> k;

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		cin >> in;
		if (in <= k)
			coin.push_back(in);
	}
	for (int i = 0; i < coin.size(); i++)
		dp[coin[i]] = 1;
	erase();
	//setting

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < coin.size(); j++) {
			if (i - coin[j] >= 1 && dp[i - coin[j]] != -1) {
				if (dp[i] != -1)
					dp[i] = min(dp[i], dp[i - coin[j]] + 1);
				else
					dp[i] = dp[i - coin[j]] + 1;
			}
		}
	}

	cout << dp[k];
	return 0;
}