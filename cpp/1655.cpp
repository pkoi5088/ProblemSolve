#include <iostream>
#include <queue>
#define endl "\n"

using namespace std;

void solve() {
	int N;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> minpq;
	priority_queue<int, vector<int>, less<int>> maxpq;
	while (N--) {
		int x;
		cin >> x;
		if (maxpq.empty() || maxpq.top() >= x) {
			maxpq.push(x);
		}
		else {
			minpq.push(x);
		}

		//개수조정
		if (maxpq.size() > minpq.size() + 1) {
			minpq.push(maxpq.top());
			maxpq.pop();
		}
		else if (minpq.size() > maxpq.size()) {
			maxpq.push(minpq.top());
			minpq.pop();
		}
		cout << maxpq.top() << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}