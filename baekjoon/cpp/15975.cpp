#include <iostream>
#include <algorithm>
#include <vector>
#define LONG 1000000001

using namespace std;

long long f(vector<pair<int,int>>& map) {
	long long r = 0;
	sort(map.begin(), map.end());
	int left = LONG, right;

	for (int i = 0; i < map.size(); i++) {
		if (i == map.size() - 1 || map[i].first != map[i + 1].first) {
			if (left != LONG) {
				r += left;
				left = LONG;
			}
		}
		else {
			right = map[i + 1].second - map[i].second;
			left > right ? r += right : r += left;
			left = right;
		}
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	vector<pair<int,int>> map;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		map.push_back({ b,a });
	}

	cout << f(map);
	return 0;
}