#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <cstring>
#define MAX 1000001
#define endl '\n'

using namespace std;

int dp[MAX], target[MAX];

void solve() {
	memset(dp, -1, sizeof(dp));
	int X;
	cin >> X;
	dp[1] = 1;
	target[1] = -1;
	
	for (int i = 2; i < X + 1; ++i) {
		if (i % 3 == 0) {
			if (dp[i] == -1 || dp[i] > dp[i / 3]) {
				dp[i] = dp[i / 3];
				target[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (dp[i] == -1 || dp[i] > dp[i / 2]) {
				dp[i] = dp[i / 2];
				target[i] = i / 2;
			}
		}
		if (dp[i] == -1 || dp[i] > dp[i - 1]) {
			dp[i] = dp[i - 1];
			target[i] = i - 1;
		}
		dp[i] += 1;
	}

	cout << dp[X] - 1 << endl;
	while (X != 1) {
		cout << X << ' ';
		X = target[X];
	}
	cout << 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
