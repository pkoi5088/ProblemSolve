#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

int combination(int n, int k) {
	if (n == k || k == 0)
		return 1;
	if (n == k + 1 || k == 1)
		return n;
	return combination(n - 1, k) + combination(n - 1, k - 1);
}

void solve() {
	int N, K;
	cin >> N >> K;
	cout << combination(N, K);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
