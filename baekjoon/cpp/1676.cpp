#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

int cnt2 = 0, cnt5 = 0;

void counting(int n) {
	while (!(n == 0) && n % 2 == 0) {
		cnt2 += 1;
		n /= 2;
	}

	while (!(n == 0) && n % 5 == 0) {
		cnt5 += 1;
		n /= 5;
	}
}

void solve() {
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++)
		counting(i);
	cout << (cnt2 > cnt5 ? cnt5 : cnt2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
