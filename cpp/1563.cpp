#include <iostream>
#include <cstring>
#define MAX 1001
#define MOD 1000000
#define endl '\n'

using namespace std;

int dp[MAX][3][3];
int N;

int getDP(int day, int late, int noshow) {
	if (late >= 2 || noshow >= 3) return 0;
	if (day >= N) return 1;
	int& ret = dp[day][late][noshow];
	if (ret != -1) return ret;

	ret = 0;
	//출석
	ret += getDP(day + 1, late, 0);
	ret %= MOD;
	//지각
	ret += getDP(day + 1, late + 1, 0);
	ret %= MOD;
	//결석
	ret += getDP(day + 1, late, noshow + 1);
	ret %= MOD;

	return ret;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N;
	cout << (getDP(1, 0, 0) + getDP(1, 1, 0) + getDP(1, 0, 1))%MOD;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
