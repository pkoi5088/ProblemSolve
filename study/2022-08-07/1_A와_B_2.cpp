#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/12919
*/

string S, T;
int ret = 0;

void f(string t) {
	if (S.size() == t.size()) {
		if (S == t)
			ret = 1;
	}
	else {
		string tmp = t;
		if (t.back() == 'A') {
			tmp.pop_back();
			f(tmp);
		}
		tmp = t;
		if (t[0] == 'B') {
			reverse(tmp.begin(), tmp.end());
			tmp.pop_back();
			f(tmp);
		}
	}
}

void solve() {
	cin >> S >> T;
	f(T);
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}