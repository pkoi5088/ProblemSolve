#include <iostream>
#include <string>
#include <queue>
#define endl '\n'

using namespace std;

void solve() {
	deque<int> deq;
	int N;
	cin >> N;
	string s;
	while (N--) {
		cin >> s;
		if (s == "push") {
			int X;
			cin >> X;
			deq.push_back(X);
		}
		else if (s == "pop") {
			if (deq.empty()) cout << -1 << endl;
			else {
				cout << deq.front() << endl;
				deq.pop_front();
			}
		}
		else if (s == "size") {
			cout << deq.size() << endl;
		}
		else if (s == "empty") {
			cout << deq.empty() << endl;
		}
		else if (s == "front") {
			if (deq.empty()) cout << -1 << endl;
			else cout << deq.front() << endl;
		}
		else if (s == "back") {
			if (deq.empty()) cout << -1 << endl;
			else cout << deq.back() << endl;
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
