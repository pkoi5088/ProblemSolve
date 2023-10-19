#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#define endl '\n'

using namespace std;

void solve() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());

	if (s[0] != '0') {
		cout << -1;
		return;
	}

	int total = 0;
	for (int i = 1; i < s.size(); ++i) {
		total += s[i] - '0';
	}

	if (total % 3 != 0) {
		cout << -1;
		return;
	}
	reverse(s.begin(), s.end());
	cout << s;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}