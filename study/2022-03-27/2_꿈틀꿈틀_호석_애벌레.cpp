#include <iostream>
#define MAX 100001
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/20181
*/

long long dp[MAX] = { 0, }, arr[MAX] = { 0, }, psum[MAX] = { 0, };
int N, K;

long long getPsum(int s, int e) {
	return psum[e] - psum[s - 1];
}

void solve() {
	cin >> N >> K;
	for (int i = 1; i <= N; ++i) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	int left = 1, right = 1;
	while (left <= N && right <= N) {
		dp[right] = max(dp[right], dp[right - 1]);
		if (getPsum(left, right) >= K) {
			dp[right] = max(dp[right], dp[left - 1] + getPsum(left, right) - K);
			if (left == right)
				right += 1;
			left += 1;
		}
		else {
			right += 1;
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