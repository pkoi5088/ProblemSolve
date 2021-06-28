#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
#define endl '\n'

using namespace std;

struct cmp {
	bool operator()(int& i1, int& i2) {
		if (abs(i1) == abs(i2)) {
			return i1 > i2;
		}
		else {
			return abs(i1) > abs(i2);
		}
	}
};

void solve() {
	priority_queue<int, vector<int>, cmp> pq;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << endl;
			}
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else {
			pq.push(x);
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
