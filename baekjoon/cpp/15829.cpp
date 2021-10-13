#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define MOD 1234567891
#define endl '\n'

using namespace std;

void solve() {
	long long result = 0, a;
	int N;
	string s;
	cin >> N >> s;
	for (int i = 0; i < s.size(); i++) {
		a = s[i] - 'a' + 1;
		for (int j = 0; j < i; j++) {
			a *= 31;
			a %= MOD;
		}
		result += a;
		result %= MOD;
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
