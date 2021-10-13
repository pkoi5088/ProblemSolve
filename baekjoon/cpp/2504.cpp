#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MAX 10001
#define endl '\n'

using namespace std;

void solve() {
	string input;
	stack<int> s;
	cin >> input;
	for (int i = 0; i < input.size(); ++i) {
		if (input[i] == '(') {
			s.push(-1);
		}
		else if (input[i] == '[') {
			s.push(-2);
		}
		else if (input[i] == ')') {
			int sum = 0;
			while (!s.empty() && s.top() >= 0) {
				sum += s.top();
				s.pop();
			}
			if (s.empty() || s.top() != -1) {
				cout << 0;
				return;
			}
			s.pop();
			if (sum == 0) s.push(2);
			else s.push(2 * sum);
		}
		else if (input[i] == ']') {
			int sum = 0;
			while (!s.empty() && s.top() >= 0) {
				sum += s.top();
				s.pop();
			}
			if (s.empty() || s.top() != -2) {
				cout << 0;
				return;
			}
			s.pop();
			if (sum == 0) s.push(3);
			else s.push(3 * sum);
		}
	}
	int result = 0;
	while (!s.empty()) {
		if (s.top() < 0) {
			cout << 0;
			return;
		}
		result += s.top();
		s.pop();
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
