#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Point {
public:
	int x = 0, y = 0;
};

bool operator<(Point p1, Point p2) {
	if (p1.x == p2.x)
		return p1.y < p2.y;
	return p1.x < p2.x;
}

vector<Point> v;

void solve() {
	int N;
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v[i].x = x;
		v[i].y = y;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		cout << v[i].x << ' ' << v[i].y << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
