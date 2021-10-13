#include <iostream>
#include <string>
#include <vector>
#define MOD 1000000

using namespace std;

int solve() {
	vector<int>	dp;
	string s;
	cin >> s;
	if (s[0] == '0')
		return 0;
	dp.resize(s.size() + 1, 0);
	dp[0] = dp[1] = 1;
	for (int i = 2; i < s.size() + 1; i++) {
		int num = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
		if (s[i - 1] != '0')
			dp[i] = (dp[i - 1] + dp[i]) % MOD;
		if (10 <= num && num <= 26)
			dp[i] = (dp[i - 2] + dp[i]) % MOD;

	}
	return dp[s.size()] % MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	cout << solve();
	return 0;
}