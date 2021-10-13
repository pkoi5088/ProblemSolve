#include <iostream>
#include <cstring>
#define MAX 16
#define INF 51
#define endl '\n'

using namespace std;

int dp[(1 << MAX)], graph[MAX][MAX];
int N, P;

int min(int a, int b) {
	if (a == -1) return b;
	if (b == -1) return a;
	return a < b ? a : b;
}

int check(int state) {
	int cnt = 0;
	while (state != 0) {
		cnt += state % 2;
		state /= 2;
	}
	return cnt;
}

int getDP(int state) {
	if (dp[state] != -1) return dp[state];
	if (check(state) >= P) return dp[state] = 0;

	for (int next = 0; next < N; ++next) {
		if (state & (1 << next)) continue;
		int cost = INF, nextState = state | (1 << next);
		for (int now = 0; now < N; ++now) {
			if (state & (1 << now)) {
				cost = min(cost, graph[now][next]);
			}
		}
		dp[state] = min(dp[state], getDP(nextState) + cost);
	}
	return dp[state];
}

void solve() {
	string tmp;
	int state = 0;
	memset(dp, -1, sizeof(dp));
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> graph[i][j];
		}
	}
	cin >> tmp >> P;
	for (int i = 0; i < tmp.size(); ++i) {
		if (tmp[i] == 'Y') state |= (1 << i);
	}
	if (check(state) == 0 && P != 0) {
		cout << -1;
	}
	else {
		cout << getDP(state);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
