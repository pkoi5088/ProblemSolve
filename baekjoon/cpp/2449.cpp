#include <iostream>
#include <cstring>
#define MAX 200
#define endl '\n'

using namespace std;

int dp[MAX][MAX], arr[MAX];
int N, K;

int min(int a, int b) {
	if (a == -1) return b;
	else if (b == -1) return a;
	return a < b ? a : b;
}

int getDP(int l, int r) {
	int& ret = dp[l][r];
	if (ret != -1) return ret;

	for (int i = l; i < r; ++i) {
		ret = min(ret, getDP(l, i) + getDP(i + 1, r) + (arr[l] != arr[i + 1]));
	}
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		dp[i][i] = 0;
	}

	cout << getDP(0, N - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
