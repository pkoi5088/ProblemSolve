#include <iostream>
#define endl '\n'

using namespace std;

void solve() {
	int sum = 0, m = -1;
	for (int i = 0; i < 7; ++i) {
		int x;
		cin >> x;
		if (x % 2) {
			if (m == -1) m = x;
			else m = min(m, x);
			sum += x;
		}
	}
	if (m == -1) cout << -1;
	else cout << sum << endl << m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
