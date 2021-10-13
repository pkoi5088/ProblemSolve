#include <iostream>
#include <string>
#include <algorithm>
#define MAX 251
#define endl '\n'

using namespace std;

string operator+(string p1, string p2) {
	string ret;
	int tmp = 0;
	while (!p1.empty() && !p2.empty()) {
		tmp += p1.back() + p2.back() - 2 * '0';
		p1.pop_back(); p2.pop_back();
		ret.push_back(tmp % 10 + '0');
		tmp /= 10;
	}
	while (!p1.empty()) {
		tmp += p1.back() - '0';
		p1.pop_back();
		ret.push_back(tmp % 10 + '0');
		tmp /= 10;
	}
	while (!p2.empty()) {
		tmp += p2.back() - '0';
		p2.pop_back();
		ret.push_back(tmp % 10 + '0');
		tmp /= 10;
	}
	while (tmp != 0) {
		ret.push_back(tmp % 10 + '0');
		tmp /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void solve() {
	string dp[MAX];
	int n;
	dp[0] = dp[1] = "1";
	for (int i = 2; i < MAX; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]);
		dp[i] = dp[i] + dp[i - 2];
	}
	while (cin >> n)
		cout << dp[n] << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
