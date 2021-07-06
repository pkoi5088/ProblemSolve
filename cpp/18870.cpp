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
	vector<int> result;
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	v.resize(N);
	result.resize(N);
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v[i] = { x,i };
	}
	sort(v.begin(), v.end());
	result[v[0].second] = 0;
	for (int i = 1; i < N; ++i) {
		if (v[i].first == v[i - 1].first) {
			result[v[i].second] = result[v[i - 1].second];
		}
		else {
			result[v[i].second] = result[v[i - 1].second] + 1;
		}
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
