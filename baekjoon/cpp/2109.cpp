#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

void solve() {
	priority_queue<int> pq;
	vector<pair<int, int>> v;
	int n, result = 0;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		v[i] = { b,a };
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; ++i) {
		if (pq.size() < v[i].first) {
			pq.push(-v[i].second);
		}
		else if (pq.top() < v[i].second) {
			pq.pop();
			pq.push(-v[i].second);
		}
	}

	while (!pq.empty()) {
		result += -pq.top();
		pq.pop();
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
