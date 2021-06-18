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

bool button[10] = { false };

bool possible(string number) {
	for (int i = 0; i < number.size(); i++) {
		if (button[number[i] - '0'] == true) {
			return false;
		}
	}
	return true;
}

void solve() {
	int N, M, result;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		button[x] = true;
	}
	result = abs(N - 100);
	for (int i = 0; i <= 1000000; i++) {
		string s = to_string(i);
		if (possible(s)) {
			result = min(result, abs(N - i) + (int)s.size());
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
