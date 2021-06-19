#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'

using namespace std;

void solve() {
	string leftStr, rightStr;
	cin >> leftStr;
	int M;
	cin >> M;
	while (M--) {
		char c;
		cin >> c;
		if (c == 'L') {
			if (!leftStr.empty()) {
				rightStr.push_back(leftStr.back());
				leftStr.pop_back();
			}
		}
		else if (c == 'D') {
			if (!rightStr.empty()) {
				leftStr.push_back(rightStr.back());
				rightStr.pop_back();
			}
		}
		else if (c == 'B') {
			if (!leftStr.empty()) {
				leftStr.pop_back();
			}
		}
		else {
			char x;
			cin >> x;
			leftStr.push_back(x);
		}
	}
	reverse(rightStr.begin(), rightStr.end());
	cout << leftStr + rightStr;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
