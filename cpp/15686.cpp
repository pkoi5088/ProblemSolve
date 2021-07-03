#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <string>
#define INF 250000
#define endl '\n'

using namespace std;

struct City {
	int x, y, chickenDist;
};

struct Shop {
	int x, y;
};

vector<City> vc;
vector<Shop> vs;
vector<int> ds;
int N, M, resultSum = INF;

int getCD(City c, Shop s) {
	return abs(c.x - s.x) + abs(c.y - s.y);
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
		if (S < resultSum) {
			resultSum = S;
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
				Shop t;
				t.x = i; t.y = j;
				vs.push_back(t);
			}
		}
	}

	for (int i = 0; i < vs.size(); i++) {
		ds.push_back(i);
		dfs();
		ds.pop_back();
	}
	cout << resultSum;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
