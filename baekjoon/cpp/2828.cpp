#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	int N, M, J;
	cin >> N >> M >> J;
	int left = 0, right = M, x, result = 0;
	while (J--) {
		cin >> x;
		if (x <= left) {
			result += left - x + 1;
			left = x - 1;
			right = left + M;
		}
		else if (x > right) {
			result += x - right;
			right = x;
			left = right - M;
		}
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
