#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 10000
#define endl '\n'

using namespace std;

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second < p2.second;
	}
};

void solve() {
	pair<int, int> station[MAX];
	int N, now, goal, cnt = 0, idx = 0;
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> station[i].first >> station[i].second;
	cin >> goal >> now;

	sort(station, station + N);
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	while (now < goal && idx < N) {
		while (idx < N && station[idx].first <= now) {
			pq.push(station[idx]);
			idx += 1;
		}
		if (!pq.empty()) {
			cnt += 1;
			now += pq.top().second;
			pq.pop();
		}
		else break;
	}
	cout << (now >= goal ? cnt : -1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
