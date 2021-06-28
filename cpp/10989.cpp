#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

void solve() {
	int N, count[10000] = { 0 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		count[x - 1] += 1;
	}
	for (int i = 0; i < 10000; i++) {
		for (int j = 0; j < count[i]; j++) {
			cout << i + 1 << '\n';
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
