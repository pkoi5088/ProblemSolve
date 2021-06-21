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
#define INF 1000000001
#define endl '\n'

using namespace std;

vector<int> seg;
int num[MAX];

long long getMax(long long a, long long b, long long c) {
	if (a > b)
		return a > c ? a : c;
	else
		return b > c ? b : c;
}

int init(int node, int start, int end) {
	if (start == end) {
		return seg[node] = start;
	}
	else {
		int mid = (start + end) / 2;
		int idx1 = init(2 * node, start, mid), idx2 = init(2 * node + 1, mid + 1, end);
		if (num[idx1] <= num[idx2]) {
			return seg[node] = idx1;
		}
		else {
			return seg[node] = idx2;
		}
	}
}

int query(int node, int start, int end, int left, int right) {
	if (right<start || left>end) {
		return INF;
	}
	else if (left <= start && end <= right) {
		return seg[node];
	}
	else {
		int mid = (start + end) / 2;
		int idx1 = query(2 * node, start, mid, left, right), idx2 = query(2 * node + 1, mid + 1, end, left, right);
		if (idx1 == INF) return idx2;
		else if (idx2 == INF) return idx1;
		if (num[idx1] <= num[idx2])
			return idx1;
		else
			return idx2;
	}
}

long long getArea(int& N, int left, int right) {
	if (left == right) {
		return num[left];
	}
	else if (left > right) {
		return -1;
	}
	else {
		int idx = query(1, 0, N - 1, left, right);
		long long ret = (right - left + 1) * (long long)num[idx];
		long long retLeft = getArea(N, left, idx - 1), retRight = getArea(N, idx + 1, right);
		return getMax(ret, retLeft, retRight);
	}
}

void solve() {
	int N, h;
	cin >> N;
	h = ceil(log2(N));
	seg.resize(1 << (h + 1));
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	init(1, 0, N - 1);

	cout << getArea(N, 0, N - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
