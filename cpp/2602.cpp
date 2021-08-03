#include <iostream>
#include <string>
#include <cstring>
#define MAX_P 20
#define MAX_T 100
#define endl '\n'

using namespace std;

int dp[2][MAX_P][MAX_T];
string pattern, text[2];

int getDP(int type, int pIdx, int tIdx) {
	if (pIdx >= pattern.size() || tIdx >= text[0].size()) return 0;
	int& ret = dp[type][pIdx][tIdx];
	if (ret != -1) return ret;

	//기저사례


	ret = getDP(type, pIdx, tIdx + 1);
	if (pattern[pIdx] == text[type][tIdx]) {
		if (pIdx == pattern.size() - 1)
			ret += 1;
		else
			ret += getDP(!type, pIdx + 1, tIdx + 1);
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> pattern >> text[0] >> text[1];
	cout << getDP(0, 0, 0) + getDP(1, 0, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
