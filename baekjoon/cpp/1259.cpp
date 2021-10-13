#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void solve() {
	while (true) {
		string s;
		cin >> s;
		if (s == "0")
			return;
		int i;
		for (i = 0; i < s.size() / 2; i++) {
			if (s[i] != s[s.size() - i - 1])
				break;
		}
		if (i == s.size() / 2)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
