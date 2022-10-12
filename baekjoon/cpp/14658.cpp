#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 101

using namespace std;

/*
	https://www.acmicpc.net/problem/14658

*/

int N, M, L, K;
pair<int, int> leftP, rightP;
vector<pair<int, int>> v;

bool check(pair<int, int> p) {
	if (leftP.first <= p.first && p.first <= rightP.first) {
		if (leftP.second <= p.second && p.second <= rightP.second) {
			return true;
		}
	}
	return false;
}

void solve() {
	cin >> N >> M >> L >> K;
	v.resize(K);
	for (int i = 0; i < K; ++i) {
		cin >> v[i].first >> v[i].second;
	}

	int ret = INF;
	for (int i = 0; i < K; ++i) {
		for (int j = 0; j < K; ++j) {
			leftP = { min(v[i].first,v[j].first),min(v[i].second,v[j].second) };
			rightP = { leftP.first + L,leftP.second + L };

			int cnt = 0;
			for (int k = 0; k < K; ++k) {
				if (check(v[k])) {
					cnt += 1;
				}
			}
			ret = min(ret, K - cnt);
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