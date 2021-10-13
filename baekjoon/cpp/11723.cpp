#include <iostream>
#include <string>

using namespace std;

void solve() {
	int M, x, set = 0;
	cin >> M;
	string s;
	while (M--) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			set |= 1 << (x - 1);
		}
		else if (s == "remove") {
			cin >> x;
			set &= ((1 << 20) - 1) ^ (1 << (x - 1));
		}
		else if (s == "check") {
			cin >> x;
			if (set & 1 << (x - 1))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "toggle") {
			cin >> x;
			set ^= 1 << (x - 1);
		}
		else if (s == "all") {
			set = (1 << 20) - 1;
		}
		else if (s == "empty") {
			set = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}