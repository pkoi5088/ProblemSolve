#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cmath>
#define MAX 100000
#define INF_MAX -1
#define INF_MIN 1000000001
#define endl '\n'

using namespace std;

vector<int> segMax, segMin;
int num[MAX];

int initMax(int node, int start, int end) {
	if (start == end) {
		return segMax[node] = num[start];
	}
	else {
		int mid = (start + end) / 2;
		return segMax[node] = max(initMax(2 * node, start, mid), initMax(2 * node + 1, mid + 1, end));
	}
}

int initMin(int node, int start, int end) {
	if (start == end) {
		return segMin[node] = num[start];
	}
	else {
		int mid = (start + end) / 2;
		return segMin[node] = min(initMin(2 * node, start, mid), initMin(2 * node + 1, mid + 1, end));
	}
}

int queryMax(int node, int start, int end, int left, int right) {
	if (right<start || left>end)
		return INF_MAX;
	else if (start >= left && right >= end)
		return segMax[node];
	else {
		int mid = (start + end) / 2;
		return max(queryMax(2 * node, start, mid, left, right), queryMax(2 * node + 1, mid + 1, end, left, right));
	}
}

int queryMin(int node, int start, int end, int left, int right) {
	if (right<start || left>end)
		return INF_MIN;
	else if (start >= left && right >= end)
		return segMin[node];
	else {
		int mid = (start + end) / 2;
		return min(queryMin(2 * node, start, mid, left, right), queryMin(2 * node + 1, mid + 1, end, left, right));
	}
}

void solve() {
	int N, M, h;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	h = ceil(log2(N));
	segMax.resize(1 << (h + 1));
	segMin.resize(1 << (h + 1));
	initMax(1, 0, N - 1);
	initMin(1, 0, N - 1);

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		cout << queryMin(1, 0, N - 1, a - 1, b - 1) << ' ' << queryMax(1, 0, N - 1, a - 1, b - 1) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
