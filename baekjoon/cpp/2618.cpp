#include <iostream>
#include <cstring>
#define MAX 1001
#define endl '\n'

using namespace std;

pair<int, int> loc[MAX];
int dp[MAX][MAX];
int N, W;

int getDist(pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int getDP(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == W || r == W) return dp[l][r] = 0;
	int now = max(l, r);
	pair<int, int> L = loc[l], R = loc[r], nextLoc = loc[now + 1];
	if (r == 0) R = { N,N };
	int leftDist = getDist(nextLoc, L) + getDP(now + 1, r), rightDist = getDist(R, nextLoc) + getDP(l, now + 1);
	return dp[l][r] = min(leftDist, rightDist);
}

void printRoute(int l, int r) {
	if (l == W || r == W) return;
	int now = max(l, r);
	pair<int, int> L = loc[l], R = loc[r], nextLoc = loc[now + 1];
	if (r == 0) R = { N,N };
	int leftDist = getDist(nextLoc, L), rightDist = getDist(R, nextLoc);
	if (dp[now + 1][r] + leftDist < dp[l][now + 1] + rightDist) {
		cout << 1 << endl;
		printRoute(now + 1, r);
	}
	else {
		cout << 2 << endl;
		printRoute(l, now + 1);
	}
}

void solve() {
	memset(dp, -1, sizeof(dp));
	cin >> N >> W;
	for (int i = 0; i < W; ++i) {
		cin >> loc[i + 1].first >> loc[i + 1].second;
	}
	loc[0] = { 1,1 };
	cout << getDP(0, 0) << endl;
	printRoute(0, 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	solve();
	return 0;
}
