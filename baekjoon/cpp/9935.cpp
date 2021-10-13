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
	string T, P, result = "";
	getline(cin, T);
	getline(cin, P);
	int begin = 0, matched = 0;
	while (begin < T.size()) {
		while (begin < T.size() && T[begin] != P.back()) {
			result.push_back(T[begin]);
			++begin;
		}
		if (begin >= T.size())
			break;
		else
			result.push_back(T[begin]);

		if (result.size() >= P.size()) {
			matched = 0;
			int rs = result.size(), ps = P.size();
			for (int i = 0; i < ps; ++i) {
				if (result[rs - i - 1] == P[ps - i - 1]) {
					++matched;
				}
			}

			if (matched == ps) {
				result.erase(rs - ps, ps);
			}
		}
		++begin;
	}

	if (result == "") {
		cout << "FRULA";
	}
	else {
		cout << result;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
