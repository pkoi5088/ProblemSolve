#include <iostream>
#include <cstring>
#define MAX 200
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/2631
*/

int dp[MAX],arr[MAX];

void solve() {
	int N, ret = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i]=1;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ret = max(ret, dp[i]);
	}
	cout<<N-ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	solve();
	return 0;
}