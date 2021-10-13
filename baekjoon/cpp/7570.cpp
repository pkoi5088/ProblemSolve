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
	v.resize(N, 0);
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x != 1)
			v[x - 1] = v[x - 2] + 1;
		else
			v[0] = 1;
		result = max(result, v[x - 1]);
	}
	cout << N - result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
