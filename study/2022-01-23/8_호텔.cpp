#include <iostream>
#include <cstring>
#define MAX_N 20
#define MAX_C 1001
#define endl '\n'

using namespace std;

/*
	https://www.acmicpc.net/problem/1106
*/

//first: 비용, second: 고객
int dp[MAX_N][MAX_C];
pair<int, int> arr[MAX_N];

//N번 홍보에서 적어도 C명을 채우는데 최소값
int getDP(int N, int C) {
	if (dp[N][C] != -1) return dp[N][C];

	//현재 돈으로 최대홍보
	dp[N][C] = arr[N].first * (C / arr[N].second + !!(C % arr[N].second));

	//i번 홍보
	for (int i = 0; i * arr[N].second <= C; ++i) {
		dp[N][C] = min(dp[N][C], getDP(N - 1, C - i * arr[N].second) + i * arr[N].first);
	}
	return dp[N][C];
}

void solve() {
	memset(dp, -1, sizeof(dp));
	int C, N;
	cin >> C >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i].first >> arr[i].second;
	for (int i = 0; i <= C; ++i) {
		dp[0][i] = arr[0].first * (i / arr[0].second + !!(i % arr[0].second));
	}
	cout << getDP(N - 1, C) << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}