#include <iostream>
#include <cstring>
#define MAX 1001
#define MOD 1000000
#define endl '\n'

using namespace std;

//dp[i][j][k]: i번째 날에 j번 지각한 상태에서 연속 결석 횟수 k
int dp[MAX][2][3];
int N;

int getDP(int day, int late, int state) {
	int& ret = dp[day][late][state];
	if (ret != -1) return ret;

	//기저사례
	if (day == N) return 1;

	ret = 0;
	//다음날 출석
	ret = (ret + getDP(day + 1, late, 0)) % MOD;

	//다음날 지각
	if (late != 1)
		ret = (ret + getDP(day + 1, late + 1, 0)) % MOD;

	//다음날 결석
	if (state != 2)
		ret = (ret + getDP(day + 1, late, state + 1)) % MOD;
	return ret % MOD;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << getDP(1, 0, 0) + getDP(1, 1, 0) + getDP(1, 0, 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
