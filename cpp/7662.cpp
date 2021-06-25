#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#define endl '\n'

using namespace std;

void solve() {
	multiset<int> ms;
	int k;
	cin >> k;
	while (k--) {
		int x;
		char c;
		cin >> c >> x;
		if (c == 'I') {
			ms.insert(x);
		}
		else if (!ms.empty()) {
			multiset<int>::iterator iter;
			if (x == 1) {
				iter = ms.end();
				--iter;
			}
			else {
				iter = ms.begin();
			}
			ms.erase(iter);
		}
	}
	if (ms.empty()) {
		cout << "EMPTY" << endl;
	}
	else {
		multiset<int>::iterator iter = ms.end();
		--iter;
		cout << *iter << ' ' << *ms.begin() << endl;
	}
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
