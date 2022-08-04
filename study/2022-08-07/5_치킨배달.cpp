#include <iostream>
#include <algorithm>
#include <vector>
#define INF 250000
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/15686
*/

struct City {
	int x, y, chickenDist;
};

vector<City> vc;
vector<pair<int, int>> vs;
vector<int> ds;
int N, M, ret = INF;

int getCD(City c, pair<int, int> s) {
	return abs(c.x - s.first) + abs(c.y - s.second);
}

void dfs() {
	if (ds.size() == M) {
		vector<int> tmp;
		tmp.resize(vc.size(), INF);
		for (int i = 0; i < vc.size(); i++) {
			for (int j = 0; j < ds.size(); j++) {
				tmp[i] = min(tmp[i], getCD(vc[i], vs[ds[j]]));
			}
		}
		int S = 0;
		for (int i = 0; i < tmp.size(); i++) {
			S += tmp[i];
		}
		if (S < ret) {
			ret = S;
		}
	}
	else {
		for (int i = ds.back() + 1; i < vs.size(); i++) {
			ds.push_back(i);
			dfs();
			ds.pop_back();
		}
	}
}

void solve() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				City t;
				t.x = i; t.y = j; t.chickenDist = INF;
				vc.push_back(t);
			}
			else if (x == 2) {
				pair<int, int> t;
				t.first = i; t.second = j;
				vs.push_back(t);
			}
		}
	}

	for (int i = 0; i < vs.size(); i++) {
		ds.push_back(i);
		dfs();
		ds.pop_back();
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
