#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MOD 10
#define endl '\n'

using namespace std;

int a, c;

int getPow(int b) {
	if (b == 0) {
		return 1;
	}
	else {
		int tmp = getPow(b / 2) % MOD;
		if (b % 2) {
			return (a * tmp * tmp) % MOD;
		}
		else {
			return (tmp * tmp) % MOD;
		}
	}
}

void solve() {
	cin >> a >> c;
	int result = getPow(c) % MOD;
	cout << (result == 0 ? 10 : result) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
