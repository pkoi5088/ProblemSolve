#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	string s, result = "";
	cin >> s;
	int cnt = 0, i = 0;
	while (i <= s.size()) {
		if (i == s.size() || s[i] == '.') {
			if (cnt % 2 == 1) {
				cout << -1;
				return;
			}
			int tmp = cnt / 2;
			while (tmp > 1) {
				result += "AAAA";
				tmp -= 2;
			}
			if (tmp)
				result += "BB";
			if (i < s.size())
				result += '.';
			cnt = 0;
		}
		else if (s[i] == 'X') {
			cnt += 1;
		}
		++i;
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
