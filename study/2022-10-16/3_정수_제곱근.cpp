#include <iostream>
#include <cmath>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2417

*/

void solve() {
	long long n, q;
	cin >> n;
	q = sqrt(n);
	if (q * q >= n) cout << q;
	else cout << q + 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}