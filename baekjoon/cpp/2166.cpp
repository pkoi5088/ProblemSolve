#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#define MAX 10000
#define endl '\n'

using namespace std;

pair<long long, long long> points[MAX];
int N;

double getArea(int a, int b) {
	double ret = (points[a].first - points[0].first) * (points[b].second - points[0].second) - (points[b].first - points[0].first) * (points[a].second - points[0].second);
	return ret / 2.0;
}

void solve() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> points[i].first >> points[i].second;
	}

	double result = 0.0;
	for (int i = 1; i < N - 1; ++i) {
		result += getArea(i, i + 1);
	}
	printf("%.1lf", abs(result));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
