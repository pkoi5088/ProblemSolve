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
	int n, s = 2;
	cin >> n;
	vector<int> fi(2), result;
	fi[0] = 0; fi[1] = 1;
	while (fi.back() < n) {
		fi.push_back(fi[s - 1] + fi[s - 2]);
		++s;
	}
	for (int i = s - 1; i >= 0; --i) {
		if (fi[i] <= n && fi[i] != 0) {
			result.push_back(fi[i]);
			n -= n / fi[i] * fi[i];
		}
	}
	for (int i = result.size() - 1; i >= 0; --i) {
		cout << result[i] << ' ';
	}
	cout << endl;
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
