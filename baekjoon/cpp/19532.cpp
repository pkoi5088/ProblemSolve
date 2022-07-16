#include <iostream>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/19532
*/

void solve() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	for (int x = -999; x < 1000; ++x) {
		for (int y = -999; y < 1000; ++y) {
			if (a * x + b * y == c && d * x + e * y == f) {
				cout << x << ' ' << y;
				return;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}