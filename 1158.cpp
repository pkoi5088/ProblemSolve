#include <iostream>
#include <queue>
#define endl '\n'

using namespace std;

void solve() {
	queue<int> q;
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
		q.push(i);
	cout << '<';
	while (!q.empty()) {
		for (int i = 0; i < K - 1; ++i) {
			q.push(q.front());
			q.pop();
		}
		int f = q.front();
		q.pop();
		if (q.empty()) {
			cout << f;
		}
		else {
			cout << f << ", ";
		}
	}
	cout << '>';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
