#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 100000

using namespace std;

/*
	https://www.acmicpc.net/problem/11663

*/

void solve() {
	int N, M;
	vector<int> v;
	cin >> N >> M;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	while (M--) {
		int s, e;
		cin >> s >> e;
		cout << (int)(upper_bound(v.begin(), v.end(), e) - lower_bound(v.begin(), v.end(), s)) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}