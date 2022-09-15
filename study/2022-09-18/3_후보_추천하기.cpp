#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 10

using namespace std;

/*
	https://www.acmicpc.net/problem/1713
*/

bool cmp(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2) {
	if (p1.second.first == p2.second.first) {
		return p1.second.second < p2.second.second;
	}
	return p1.second.first > p2.second.first;
}

void solve() {
	//{번호,{개수,시간}}
	vector<pair<int, pair<int, int>>> v;
	int N, M;
	cin >> N >> M;
	while (M--) {
		int num, idx;
		cin >> num;
		for (idx = 0; idx < v.size(); ++idx) {
			if (v[idx].first == num) break;
		}
		if (idx == v.size()) {
			if (v.size() < N) {
				v.push_back({ num,{1,M} });
			}
			else if (v.size() == N) {
				sort(v.begin(), v.end(), cmp);
				v.pop_back();
				v.push_back({ num,{1,M} });
			}
		}
		else {
			v[idx].second.first += 1;
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].first << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}