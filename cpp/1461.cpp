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
	vector<int> v;
	int N, M, result = 0, zeroIdx = 0;
	cin >> N >> M;
	v.resize(N + 1);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
		if (v[i] < 0)
			zeroIdx += 1;
	}
	v[N] = 0;
	sort(v.begin(), v.end());

	for (int i = 0; i < zeroIdx; i += M)
		result += -v[i] * 2;
	for (int i = N; i > zeroIdx; i -= M)
		result += v[i] * 2;
	result -= max(abs(v[0]), abs(v[N]));
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
