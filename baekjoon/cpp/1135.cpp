#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define endl '\n'
#define MAX 50

using namespace std;

int N, dp[MAX];
vector<vector<int>> child;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	return p1.second > p2.second;
}

int getDP(int idx) {
	int& ret = dp[idx];
	if (ret != -1) return ret;

	// 부하가 없으면 0초
	if (child[idx].size() == 0) return ret = 0;

	vector<pair<int, int>> v;
	for (int i = 0; i < child[idx].size(); ++i) {
		int next = child[idx][i];
		int nextDP = getDP(next);
		v.push_back({ next,nextDP });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); ++i) {
		ret = max(ret, v[i].second + i + 1);
	}
	return ret;
}

void solve() {
	cin >> N;
	memset(dp, -1, sizeof(dp));
	child.resize(N);
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		if (a != -1) child[a].push_back(i);
	}

	cout << getDP(0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}