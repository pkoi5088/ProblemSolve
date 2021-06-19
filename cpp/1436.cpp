#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void solve() {
	int N, cnt = 0;
	cin >> N;
	for (int i = 666;; i++) {
		string s = to_string(i);
		if (s.find("666") != string::npos) {
			if (++cnt == N) {
				cout << i;
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
