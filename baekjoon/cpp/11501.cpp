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
	long N, i, height, cnt = 0, money = 0;
	cin >> N;
	v.resize(N);
	for (int j = 0; j < N; ++j)
		cin >> v[j];

	i = N - 2;
	height = v[N - 1];
	while (i >= 0) {
		if (v[i] > height) {
			money += height * cnt;
			height = v[i];
			cnt = 0;
		}
		else {
			money -= v[i];
			cnt += 1;
		}
		i -= 1;
	}
	money += height * cnt;
	cout << money << endl;
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
