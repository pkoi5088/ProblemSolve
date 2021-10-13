#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
#define MAX 1000
#define endl '\n'

using namespace std;

//0: 근우, 1:명우
int dp[MAX][MAX][2], num[MAX];

//a~b에서 who의 차례일 때 얻을 수 있는 최대 값
int pick(int a, int b, int who) {
	if (dp[a][b][who] != -1) return dp[a][b][who];
	else if (a == b) return dp[a][b][who] = (who == 0 ? num[a] : 0);
	if (who == 0) {
		return dp[a][b][who] = max(pick(a + 1, b, !who) + num[a], pick(a, b - 1, !who) + num[b]);
	}
	else {
		return dp[a][b][who] = min(pick(a + 1, b, !who), pick(a, b - 1, !who));
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	cout << pick(0, N - 1, 0) << endl;
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
