#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

bool isBalance(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (st.empty() || st.top() != '(')
				return false;
			st.pop();
		}
		else if (s[i] == ']') {
			if (st.empty() || st.top() != '[')
				return false;
			st.pop();
		}
	}
	return st.empty();
}

void solve() {
	string s;
	while (true) {
		getline(cin, s, '.');
		if (s.size() == 1)
			return;
		if (isBalance(s))
			cout << "yes\n";
		else
			cout << "no\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
