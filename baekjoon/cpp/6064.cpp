#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int gcd(int a, int b) {
	return (b == 0 ? a : gcd(b, a % b));
}

int f(int a, int b) {
	return a * b / gcd(a, b);
}

void solve() {
	int M, N, x, y;
	cin >> M >> N >> x >> y;
	int maxX = f(M, N);
	for (; x <= maxX; x += M) {
		if ((x - 1) % N + 1 == y) {
			cout << x << endl;
			return;
		}
	}
	cout << -1 << endl;
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
