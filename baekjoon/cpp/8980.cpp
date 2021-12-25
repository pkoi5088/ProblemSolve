#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

bool cmp(pair<pair<int, int>, int>p1, pair<pair<int, int>, int>p2) {
	if (p1.first.second == p2.first.second)
		return p1.first.first < p1.first.first;
	return p1.first.second < p2.first.second;
}

int getMin(vector<int> capacity, int start, int end) {
	int ret = capacity[start];
	for (int i = start + 1; i < end; ++i) {
		ret = min(ret, capacity[i]);
	}
	return ret;
}

void solve() {
	vector<pair<pair<int, int>, int>> v;
	vector<int> capacity;
	int N, M, C;
	cin >> N >> C >> M;
	v.resize(M);
	capacity.resize(N + 1, C);
	for (int i = 0; i < M; ++i) {
		cin >> v[i].first.first >> v[i].first.second >> v[i].second;
	}
	sort(v.begin(), v.end(), cmp);

	int ret = 0;
	for (int i = 0; i < M; ++i) {
		int start = v[i].first.first, end = v[i].first.second, box = v[i].second;
		int c = min(box, getMin(capacity, start, end));
		ret += c;
		for (int i = start; i < end; ++i) {
			capacity[i] -= c;
		}
	}
	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}