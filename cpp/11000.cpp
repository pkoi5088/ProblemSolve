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

struct cmp {
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

void solve() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	vector<pair<int, int>> v;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; ++i) {
		if (pq.empty() || pq.top().second > v[i].first) {
			pq.push({ v[i] });
		}
		else {
			pair<int, int> tmp = pq.top();
			pq.pop();
			tmp.second = v[i].second;
			pq.push(tmp);
		}
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
