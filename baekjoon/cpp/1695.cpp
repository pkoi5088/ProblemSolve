#include <iostream>
#include <cstring>
#define MAX 5000
#define endl '\n'

using namespace std;

int dp[MAX][MAX], arr[MAX];
int N;

int getDP(int l, int r) {
	if (l >= r) return 0;

	int& ret = dp[l][r];
	if (ret != -1) return ret;

	if (arr[l] == arr[r]) return ret = getDP(l + 1, r - 1);
	else return ret = min(getDP(l + 1, r), getDP(l, r - 1)) + 1;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	cout << getDP(0, N - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
