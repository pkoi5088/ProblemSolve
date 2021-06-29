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
#define MOD 1000000007
#define MAX 1000000
#define endl '\n'

using namespace std;

vector<long long> seg;
int num[MAX];

long long init(int node, int start, int end) {
	if (start == end) {
		return seg[node] = num[start];
	}
	else {
		int mid = (start + end) / 2;
		return seg[node] = (init(2 * node, start, mid) * init(2 * node + 1, mid + 1, end)) % MOD;
	}
}

long long update(int node, int start, int end, int index) {
	if (index<start || index>end)
		return seg[node];
	else if (start == end)
		return seg[node] = num[start];
	else {
		int mid = (start + end) / 2;
		return seg[node] = (update(2 * node, start, mid, index) * update(2 * node + 1, mid + 1, end, index)) % MOD;
	}
}

long long query(int node, int start, int end, int left, int right) {
	if (right < start || end < left)
		return 1;
	else if (left <= start && end <= right)
		return seg[node];
	else {
		int mid = (start + end) / 2;
		return (query(2 * node, start, mid, left, right) * query(2 * node + 1, mid + 1, end, left, right)) % MOD;
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
	init(1, 0, N - 1);

	for (int i = 0; i < M + K; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			num[b - 1] = c;
			update(1, 0, N - 1, b - 1);
		}
		else {
			cout << query(1, 0, N - 1, b - 1, c - 1) % MOD << endl;
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
