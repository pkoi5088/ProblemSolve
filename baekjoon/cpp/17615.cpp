#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

void solve() {
	int N, cnt[2] = { 0 }, cntSide[2] = { 0 };
	string s;
	cin >> N >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'R') cnt[0]++;
		else cnt[1]++;
	}

	//앞
	int idx = (s[0] == 'R' ? 0 : 1), tmp = 1;
	for (int i = 0; i < N - 1 && s[i] == s[i + 1]; ++i) {
		tmp++;
	}
	cntSide[idx] = max(cntSide[idx], tmp);

	//뒤
	idx = (s[N - 1] == 'R' ? 0 : 1), tmp = 1;
	for (int i = N - 1; i > 0 && s[i] == s[i - 1]; --i) {
		tmp++;
	}
	cntSide[idx] = max(cntSide[idx], tmp);

	int ret = 5000000;
	for (int i = 0; i < 2; ++i) {
		ret = min(ret, cnt[i] - cntSide[i]);
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