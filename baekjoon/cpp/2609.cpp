#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void solve() {
	int a, b, t;
	cin >> a >> b;
	if (a < b)
		swap(a, b);
	t = gcd(a, b);
	cout << t << endl;
	for (int i = t;; i += t) {
		if (i % a == 0 && i % b == 0) {
			cout << i;
			return;
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
