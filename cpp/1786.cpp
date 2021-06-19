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

//i번 인덱스까지 맞았을 때의 스킵양, i<|P|+2
vector<int> skip;

void getSkip(const string& P) {
	int m = P.size();
	skip.resize(m,0);
	int begin = 1, matched = 0;
	while (begin + matched < m) {
		if (P[begin + matched] == P[matched]) {
			++matched;
			skip[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - skip[matched - 1];
				matched = skip[matched - 1];
			}
		}
	}
}

void solve() {
	string T, P;
	getline(cin, T);
	getline(cin, P);
	getSkip(P);

	vector<int> result;
	int n = T.size(), m = P.size();
	int begin = 0, matched = 0;
	while (begin <= n - m) {
		if (matched < m && T[begin + matched] == P[matched]) {
			++matched;
			if (matched == m) result.push_back(begin + 1);
		}
		else {
			if (matched == 0) ++begin;
			else {
				begin += matched - skip[matched - 1];
				matched = skip[matched - 1];
			}
		}
	}
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
