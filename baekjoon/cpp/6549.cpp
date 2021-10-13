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
#define INF -1
#define endl '\n'

using namespace std;

int num[MAX];

long long getMax(long long a, long long b, long long c) {
	if (a > b)
		return a > c ? a : c;
	else
		return b > c ? b : c;
}

int init(vector<int>& tree, int node, int start, int end) {
	if (start == end) {
		return tree[node] = start;
	}
	else {
		int mid = (start + end) / 2;
		int idx1 = init(tree, 2 * node, start, mid), idx2 = init(tree, 2 * node + 1, mid + 1, end);
		if (num[idx1] <= num[idx2]) {
			return tree[node] = idx1;
		}
		else {
			return tree[node] = idx2;
		}
	}
}

int queryMin(vector<int>& tree, int node, int start, int end, int left, int right) {
	if (start > right || end < left)
		return INF;
	else if (start >= left && end <= right)
		return tree[node];
	else {
		int mid = (start + end) / 2;
		int idx1 = queryMin(tree, 2 * node, start, mid, left, right), idx2 = queryMin(tree, 2 * node + 1, mid + 1, end, left, right);
		if (idx1 == INF)
			return idx2;
		else if (idx2 == INF)
			return idx1;

		if (num[idx1] <= num[idx2]) {
			return idx1;
		}
		else {
			return idx2;
		}
	}
}

//left~right에서 넓이 최대값
long long getArea(vector<int>& tree, int& N, int left, int right) {
	if (left == right) {
		return num[left];
	}
	else if (right < left) {
		return -1;
	}
	int idx = queryMin(tree, 1, 0, N - 1, left, right);
	if (idx == INF)
		return -1;
	long long ret = (right - left + 1) * (long long)num[idx];
	long long retLeft = getArea(tree, N, left, idx - 1);
	long long retRight = getArea(tree, N, idx + 1, right);
	return getMax(ret, retLeft, retRight);
}

void solve() {
	while (true) {
		vector<int> segMin;
		int N, h;
		cin >> N;
		if (N == 0)
			break;
		h = ceil(log2(N));
		segMin.resize(1 << (h + 1));
		for (int i = 0; i < N; ++i) {
			cin >> num[i];
		}
		init(segMin, 1, 0, N - 1);
		cout << getArea(segMin, N, 0, N - 1) << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
