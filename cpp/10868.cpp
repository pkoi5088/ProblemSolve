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

int init(int node, int start, int end) {
	if (start == end) {
		return seg[node] = num[start];
	}
	else {
		int mid = (start + end) / 2;
		return seg[node] = min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
	}
}

int query(int node, int start, int end, int left, int right) {
	if (right<start||left>end) {
		return INF;
	}
	else if (left <= start && end <= right) {
		return seg[node];
	}
	else {
		int mid = (start + end) / 2;
		return min(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, left, right));
	}
}

void solve() {
	int N, M, h;
	cin >> N >> M;
	h = ceil(log2(N));
	seg.resize(1 << (h + 1));
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	init(1, 0, N - 1);

	int a, b;
	for (int i = 0; i < M; ++i) {
		cin >> a >> b;
		cout << query(1, 0, N - 1, a - 1, b - 1) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
