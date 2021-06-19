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
#define endl '\n'

using namespace std;

vector<long long> v, num;
int N, M, K;

//v[node]는 num[start:end]구간을 나타낸다.
long long init(int node, int start, int end) {
	if (start == end)
		return v[node] = num[start];

	int mid = (start + end) / 2;
	return v[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

//num[idx]를 after로 바꾼다
void update(int node, int start, int end, long long idx, long long after) {
	if (start > idx || idx > end) {
		return;
	}
	else {
		v[node] += after - num[idx];
		if (start < end) {
			int mid = (start + end) / 2;
			update(2 * node, start, mid, idx, after);
			update(2 * node + 1, mid + 1, end, idx, after);
		}
	}
}

//구간 [left, right]구간합을 구한다.
long long query(int node, int start, int end, long long left, long long right) {
	if (start > right || end < left)
		return 0;
	else if (start >= left && right >= end)
		return v[node];
	else {
		int mid = (start + end) / 2;
		return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
	}
}

void solve() {
	cin >> N >> M >> K;
	int h = ceil(log2(N));
	v.resize(1 << (h + 1));
	num.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	init(1, 0, N - 1);

	long long a, b, c;
	for (int i = 0; i < M + K; ++i) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 0, N - 1, b - 1, c);
			num[b - 1] = c;
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
