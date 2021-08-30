#include <iostream>
#include <string>
#include <cstring>
#define MAX 10
#define endl '\n'

using namespace std;

int dp[MAX][1 << MAX], arr[MAX];
int N, M;

//n<N보장, true면 안되는 상황
bool check(int type, int parent) {
	for (int i = 0; i < M; ++i) {
		if (type & (1 << i)) {
			if (i != 0 && (parent & (1 << (i - 1)))) return true;
			if (i != M - 1 && (parent & (1 << (i + 1)))) return true;
		}
	}
	return false;
}

int getDP(int n, int type, int parent) {
	int& ret = dp[n][type];
	if (ret != -1) return ret;

	//기저사례
	//1. 부서진 책상이면
	if (arr[n] & type) return ret = 0;
	//2. 연달아서 앉으면
	int cnt = 0, tmp = type;
	while (tmp != 0) {
		cnt += tmp % 2;
		if ((tmp & 3) == 3) return ret = 0;
		tmp /= 2;
	}

	if (n == 0) {
		return ret = cnt;
	}
	else {
		tmp = 0;
		for (int i = 0; i < (1 << M); ++i) {
			if (check(i, type)) continue;
			tmp = max(tmp, getDP(n - 1, i, type));
		}
		return ret = tmp + cnt;
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));
	memset(arr, 0, sizeof(arr));
	cin >> N >> M;
	string tmp;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		for (int j = 0; j < M; ++j) {
			if (tmp[j] == 'x')
				arr[i] |= (1 << (M - 1 - j));
		}
	}
	int ret = 0;
	for (int i = 0; i < (1 << M); ++i) {
		ret = max(ret, getDP(N - 1, i, 0));
	}
	cout << ret << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int C;
	cin >> C;
	while (C--)
		solve();
	return 0;
}
