#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <string>
#define INF 10001
#define endl '\n'

using namespace std;

struct Schedule {
	int from, to, weight;
};

bool operator<(Schedule& s1, Schedule& s2) {
	if (s1.to == s2.to)
		return s1.from < s2.from;
	return s1.to < s2.to;
}

void solve() {
	vector<Schedule> village;
	vector<int> weight;
	int N, C, M, result = 0;
	cin >> N >> C >> M;
	weight.resize(N, 0);
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		Schedule tmp;
		tmp.from = a - 1; tmp.to = b - 1; tmp.weight = c;
		village.push_back(tmp);
	}
	sort(village.begin(), village.end());

	for (int i = 0; i < M; ++i) {
		int from = village[i].from, to = village[i].to;
		int rest = village[i].weight;
		for (int j = from; j < to; ++j) {
			rest = min(rest, C - weight[j]);
		}
		for (int j = from; j < to; ++j) {
			weight[j] += rest;
		}
		result += rest;
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
