#include <iostream>
#define MAX 101
#define endl '\n'

using namespace std;

void solve() {
	long long dp[MAX];
	int N;
	cin >> N;
	for (int i = 1; i < 7; ++i)
		dp[i] = i;
	for (int i = 7; i <= N; ++i) {
		dp[i] = dp[i - 1];
		for (int j = 3; i - j > 0; ++j) {
			if (dp[i] < dp[i - j] * (j - 1)) {
				dp[i] = dp[i - j] * (j - 1);
			}
		}
	}
	cout << dp[N];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
