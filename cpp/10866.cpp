#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>

using namespace std;

void solve() {
	deque<int> d;
	int N;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		if (s == "push_front") {
			int x;
			cin >> x;
			d.push_front(x);
		}
		else if (s == "push_back") {
			int x;
			cin >> x;
			d.push_back(x);
		}
		else if (s == "pop_front") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (s == "size") {
			cout << d.size() << '\n';
		}
		else if (s == "empty") {
			cout << d.empty() << '\n';
		}
		else if (s == "front") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.front() << '\n';
			}
		}
		else if (s == "back") {
			if (d.empty())
				cout << -1 << '\n';
			else {
				cout << d.back() << '\n';
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
