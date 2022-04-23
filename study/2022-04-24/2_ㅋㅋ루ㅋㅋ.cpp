#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/20442
*/

void solve() {
	vector<int> leftK, rightK;
	string s;
	cin >> s;
	int cnt = 0, ret = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'K') cnt += 1;
		else leftK.push_back(cnt);
	}
	cnt = 0;
	for (int i = s.size() - 1; i >= 0; --i) {
		if (s[i] == 'K') cnt += 1;
		else rightK.push_back(cnt);
	}
	reverse(rightK.begin(), rightK.end());

	int left = 0, right = rightK.size() - 1;
	while (left <= right) {
		ret = max(ret, right - left + 1 + min(leftK[left], rightK[right]) * 2);
		if (leftK[left] < rightK[right]) left += 1;
		else right -= 1;
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}