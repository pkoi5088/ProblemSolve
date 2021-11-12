#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'

using namespace std;

void solve() {
	string N, ret;
	cin >> N;
	if (N == "0") cout << 0;
	vector<string> v = {
		"000",
		"100",
		"010",
		"110",
		"001",
		"101",
		"011",
		"111"
	};
	for (int i = N.size() - 1; i >= 0; --i) {
		ret += v[N[i] - '0'];
	}
	while (ret.back() == '0')
		ret.pop_back();
	reverse(ret.begin(), ret.end());
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
