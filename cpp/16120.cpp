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
	string s, tmp = "";
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'A' || tmp.size() < 3) {
			tmp += s[i];
		}
		else {
			int N = tmp.size();
			if (tmp[N - 3] == 'P' && tmp[N - 2] == 'P' && tmp[N - 1] == 'A') {
				tmp.pop_back();
				tmp.pop_back();
				tmp.pop_back();
			}
			tmp += 'P';
		}
	}
	if (tmp == "P" || tmp == "PPAP") {
		cout << "PPAP";
	}
	else {
		cout << "NP";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
