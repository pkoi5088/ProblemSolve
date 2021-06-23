#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define endl '\n'

using namespace std;

//VIP석 사이의 칸이 k개일 때 추가되는 경우의 수
int dp[41] = { 0 };

void solve() {
	dp[0] = dp[1] = 1;
	for (int i = 2; i < 41; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	vector<int> v;
	int N, M, result = 1, left = 0, right;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> right;
		result *= dp[right - left - 1];
		left = right;
	}
	result *= dp[N - left];
	cout << result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
