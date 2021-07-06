#include <iostream>
#include <algorithm>
#define MAX 5000
#define endl "\n"

using namespace std;

void solve() {
	int power[2 * MAX];
	int n, ret = 200000;
	cin >> n;
	for (int i = 0; i < 2 * n; ++i)
		cin >> power[i];
	sort(power, power + 2 * n);
	for (int i = 0; i < n; ++i) {
		ret = min(ret, power[i] + power[2 * n - 1 - i]);
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}