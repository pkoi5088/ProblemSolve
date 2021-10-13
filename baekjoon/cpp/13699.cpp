#include <iostream>
#define MAX 36
#define endl '\n'

using namespace std;

long long dp[MAX] = { 0, };

long long getDP(int n) {
	if (dp[n] != 0) return dp[n];
	
	//기저사례
	if (n == 0) return dp[n] = 1;

	long long& ret = dp[n];
	for (int i = 0; i < n; ++i) {
		ret += getDP(i) * getDP(n - 1 - i);
	}
	return ret;
}

void solve() {
	int n;
	cin >> n;
	cout << getDP(n);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
