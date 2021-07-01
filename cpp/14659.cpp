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
	vector<int> v;
	int N, result = -1;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}

	for (int i = 0; i < N; ++i) {
		int cnt = 0;
		for (int j = i + 1; j < N; ++j) {
			if (v[i] < v[j])
				break;
			cnt += 1;
		}
		result = max(result, cnt);
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
