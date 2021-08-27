#include <iostream>
#include <cstring>
#define MAX 100000
#define INF 987654321
#define endl '\n'

using namespace std;

int dp[MAX][3], arr[MAX][3];
int N;

int getDP(int n, int type) {
	if (type < 0) return INF;
	int& ret = dp[n][type];
	if (ret != INF) return ret;

	//왼쪽
	ret = getDP(n, type - 1) + arr[n][type];

	//위쪽
	for (int i = 0; i < 3; ++i) {
		if (abs(i - type) < 2) {
			ret = min(ret, getDP(n - 1, i) + arr[n][type]);
		}
	}
	return ret;
}

void solve() {
	int count = 1;
	while (true) {
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 3; ++j) {
				cin >> arr[i][j];
				dp[i][j] = INF;
			}
		}

		dp[0][0] = INF + 1;
		dp[0][1] = arr[0][1];
		dp[0][2] = dp[0][1] + arr[0][2];

		cout << count << ". " << getDP(N - 1, 1) << endl;
		count++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
