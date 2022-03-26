#include <iostream>
#define MAX 101
#define INF 9000000000000000000
#define endl '\n'

using namespace std;

/*
    https://www.acmicpc.net/problem/3687
*/

long long dp[MAX];
int arr[8] = { -1,-1,1,7,4,2,0,8 };

void solve() {
	for (int i = 0; i < MAX; ++i) {
		dp[i] = INF;
	}
	dp[1] = 9;
	dp[2] = 1;
	dp[3] = 7;
	dp[4] = 4;
	dp[5] = 2;
	dp[6] = 6;
	dp[7] = 8;
	for (int i = 8; i < MAX; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (arr[j] == -1) continue;
			dp[i] = min(dp[i], dp[i - j] * 10 + arr[j]);
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n] << ' ';
		while (n) {
			if (n % 2) {
				cout << '7';
				n -= 3;
			}
			else {
				cout << '1';
				n -= 2;
			}
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}