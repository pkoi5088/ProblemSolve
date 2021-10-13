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

int coin[4] = { 25,10,5,1 };

void solve() {
	vector<int> v(4, 0);
	int C;
	cin >> C;
	for (int i = 0; i < 4; ++i) {
		v[i] += C / coin[i];
		C -= v[i] * coin[i];
		cout << v[i] << ' ';
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
