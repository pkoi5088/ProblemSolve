#include <iostream>
#include <vector>
#include <cmath>
#define endl '\n'
#define INF 2000000000

using namespace std;

/*
	https://www.acmicpc.net/problem/2961
*/

int N;
vector<pair<int, int>> v;

pair<int,int> min(pair<int, int> p1, pair<int, int> p2) {
	if (abs(p1.first - p1.second) < abs(p2.first - p2.second)) {
		return p1;
	}
	return p2;
}

pair<int, int> getTaste(int order) {
	pair<int, int> ret = { 1,0 };
	int cnt = 0;
	while (order != 0) {
		if (order % 2) {
			ret.first *= v[cnt].first;
			ret.second += v[cnt].second;
		}
		order /= 2;
		cnt += 1;
	}
	return ret;
}

void solve() {
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	pair<int, int> ret = { 0,INF };
	for (int i = 1; i < (1 << N); ++i) {
		ret = min(ret, getTaste(i));
	}
	cout << abs(ret.first - ret.second);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}