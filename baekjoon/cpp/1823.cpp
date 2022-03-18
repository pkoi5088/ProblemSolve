#include <iostream>
#include <cstring>
#define MAX 2000
#define endl '\n'

using namespace std;

int min(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	return a < b ? a : b;
}

int dp[MAX][MAX], arr[MAX];
int N;

int getDP(int start, int end) {
	int& ret = dp[start][end];
	if (ret != -1) return ret;

	int day = start + N - end;

	//기저사례
	if (start == end)
		return ret = arr[start] * day;

	ret = max(getDP(start, end - 1) + arr[end] * day, getDP(start + 1, end) + arr[start] * day);
	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	cout << getDP(0, N - 1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}