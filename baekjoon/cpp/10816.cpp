#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

void solve() {
	vector<int> v;
	int N, M;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	cin >> M;
	sort(v.begin(), v.end());
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		cout << upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x) << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
