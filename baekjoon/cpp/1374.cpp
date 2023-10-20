#include <iostream>
#include <queue>
#include <algorithm>
#define endl '\n'

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

void solve() {
	int N;
	vector<pair<int, int>> v;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), compare);

	priority_queue<int, vector<int>, greater<int>> pq;
	for (auto p : v) {
		int start = p.first, end = p.second;
		if (!pq.empty() && start >= pq.top()) {
			pq.pop();
		}
		pq.push(end);
	}
	cout << pq.size();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}