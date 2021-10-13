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

string S, result = "";

void solve() {
	cin >> S;
	stack<char> op;
	int index = 0;
	while (index < S.size()) {
		char now = S[index];
		if (isalpha(now)) {
			result.push_back(now);
		}
		else if (now == '(') {
			op.push(now);
		}
		else if (now == '+' || now == '-') {
			while (!op.empty() && op.top() != '(') {
				result.push_back(op.top());
				op.pop();
			}
			op.push(now);
		}
		else if (now == '*' || now == '/') {
			while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
				result.push_back(op.top());
				op.pop();
			}
			op.push(now);
		}
		else {
			while (op.top() != '(') {
				result.push_back(op.top());
				op.pop();
			}
			op.pop();
		}
		++index;
	}
	while (!op.empty()) {
		result.push_back(op.top());
		op.pop();
	}
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
