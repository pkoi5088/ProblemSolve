#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#define MOD 1000000009
#define MAX 100000
#define endl '\n'

using namespace std;

//벡터 resize를 사용하면 시간초과 발생
unsigned int dp[3][MAX] = { 0 };

void solve() {
	//마지막으로 더한 수가 1,2,3일 때
	int N;
	cin >> N;
	
	dp[0][0] = 1;
	dp[1][0] = dp[2][0] = 0;
	dp[0][1] = dp[2][1] = 0;
	dp[1][1] = 1;
	dp[0][2] = dp[1][2] = dp[2][2] = 1;

	for (int i = 3; i < N; ++i) {
		dp[0][i] = (dp[1][i - 1] + dp[2][i - 1]) % MOD;
		dp[1][i] = (dp[0][i - 2] + dp[2][i - 2]) % MOD;
		dp[2][i] = (dp[0][i - 3] + dp[1][i - 3]) % MOD;
	}
	cout << (dp[0][N - 1] + dp[1][N - 1] + dp[2][N - 1]) % MOD << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
