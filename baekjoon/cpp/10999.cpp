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
#define MAX 1000000
#define endl '\n'

using namespace std;

vector<long long> seg, lazy;
long long num[MAX];

long long init(int node, int start, int end) {
	if (start == end) {
		return seg[node] = num[start];
	}
	else {
		int mid = (start + end) / 2;
		return seg[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
	}
}

void updateLazy(int node, int start, int end) {
	if (lazy[node] == 0)
		return;
	seg[node] += (end - start + 1) * lazy[node];
	if (start != end) {
		lazy[2 * node] += lazy[node];
		lazy[2 * node + 1] += lazy[node];
	}
	lazy[node] = 0;
}

//구간 left-right
void update(int node, int start, int end, int left, int right, long long dist) {
	updateLazy(node, start, end);
	if (right < start || end < left)
		return;
	else if (left <= start && end <= right) {
		seg[node] += (end - start + 1) * dist;
		if (start != end) {
			lazy[2 * node] += dist;
			lazy[2 * node + 1] += dist;
		}
	}
	else {
		int mid = (start + end) / 2;
		update(2 * node, start, mid, left, right, dist);
		update(2 * node + 1, mid + 1, end, left, right, dist);
		seg[node] = seg[2 * node] + seg[2 * node + 1];
	}
}

long long query(int node, int start, int end, int left, int right) {
	updateLazy(node, start, end);
	if (right < start || end < left)
		return 0;
	else if (left <= start && end <= right) {
		return seg[node];
	}
	else {
		int mid = (start + end) / 2;
		return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
	}
}

void solve() {
	int N, M, K, h;
	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	h = ceil(log2(N));
	seg.resize(1 << (h + 1));
	lazy.resize(1 << (h + 1), 0);
	init(1, 0, N - 1);

	long long a, b, c, d;
	for (int i = 0; i < M + K; ++i) {
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			update(1, 0, N - 1, b - 1, c - 1, d);
		}
		else {
			cout << query(1, 0, N - 1, b - 1, c - 1) << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
